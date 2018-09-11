#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include "myhead.h"

void BookBorrow()//�������
{
    struct BookInfo borrowBook;
    struct BorrowInfo borrowRecord;
    struct ReaderInfo borrowReader;
    FILE *fpBook, *fpReader, *fpBorrow;
    char bookCode[10];
    char readerCode[10];
    int bookIndex = 0, readerIndex = 0;
    printf("******�������******\n");
    scanf("%s", bookCode);
    if(! IsBookExist(bookCode))
    {
        printf("���Ϊ%s��ͼ�鲻���ڣ�����ʧ�ܣ�\n", bookCode);
        return ;
    }
    if(IsBorrowOut(bookCode))
    {
        printf("���Ϊ%s��ͼ���ѱ�ȫ�����������ʧ�ܣ�\n", bookCode);
        return ;
    }
    printf("������߱�ţ�");
    scanf("%s", readerCode);
    if(!IsReaderExist(readerCode))
    {
        printf("���Ϊ%s�Ķ��߲����ڣ�����ʧ��!\n", readerCode);
        return ;
    }
    if(!CouldBorrow(readerCode))
    {
        printf("���Ϊ%s�Ķ��߽������������뻹����ٽ�!\n", readerCode);
        return ;
    }
    if((fpBook = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("�����޷��򿪶�����Ϣ�ļ���\n");
        return ;
    }
    if((fpBorrow = fopen("borrowinfo.dat", "rb+")) == NULL)
    {
        printf("�����޷��򿪽�����Ϣ�ļ���\n");
        return ;
    }
    bookIndex = GetPosition(bookCode, &borrowBook);         //��λ���ĵ�ͼ��
    readerIndex = GetRdPosition(readerCode, &borrowReader);     //��λ������
    borrowBook.borrowNum = borrowBook.borrowNum + 1;
    borrowReader.borrowBookNum = borrowReader.borrowBookNum + 1;
    strcpy(borrowRecord.bookCode, bookCode);
    strcpy(borrowRecord.readerCode, readerCode);
    time_t t = time(NULL);
    strcpy(borrowRecord.borrowDate, ctime(&t));
    strcpy(borrowRecord.borrowHandler, handler);
    borrowRecord.bookStatus = '0';
    fseek(fpBook, (long)BOOKLEN * bookIndex, SEEK_SET);         //��д��ͼ����ѽ������
    fwrite(&borrowBook, BOOKLEN, 1, fpBook);
    fseek(fpReader, (long)READERLEN * readerIndex, SEEK_SET);       //��д�����˵��ѽ���ͼ����
    fwrite(&borrowReader, READERLEN, 1, fpReader);
    fseek(fpBorrow, 0, SEEK_END);               //����ͼ����ļ�¼
    fwrite(&borrowRecord, BORROWLEN, 1, fpBorrow);
    fclose(fpBook);
    fclose(fpReader);
    fclose(fpBorrow);
    printf("ͼ����ĳɹ����س���������\n");
    getchar();
    getchar();
}

void BookReturn()//�������
{
    struct BookInfo returnBook;
    struct BorrowInfo returnRecord;
    struct ReaderInfo returnReader;
    FILE *fpBook, *fpReader, *fpBorrow;
    char bookCode[10];
    char readerCode[10];
    int BookIndex =0, readerIndex = 0, borrowIndex = 0;
    if(CountBook() == 0 || CountReader() == 0)
    {
        printf("����û��ͼ����߶�����Ϣ���޷�ִ�л��������\n");
        return ;
    }
    printf("******�������******\n");
    printf("      ����ͼ���ţ�");
    scanf("%s", bookCode);
    if(! IsBookExist(bookCode))
    {
        printf("���Ϊ%s��ͼ�鲻���ڣ�����ʧ�ܣ�\n", bookCode);
        return ;
    }
    if(!IsBook(bookCode))
    {
        printf("���Ϊ%s��ͼ��δ�����������ʧ�ܣ�\n", bookCode);
        return ;
    }
    printf("������߱�ţ�");
    scanf("%s", readerCode);
    if(!IsReaderExist(readerCode))
    {
        printf("���Ϊ%s�Ķ��߲����ڣ�����ʧ�ܣ�\n", readerCode);
        return ;
    }
    if(!IsBorrowed(readerCode))
    {
        printf("���Ϊ%s�Ķ���û�н����¼���޷����飡\n", readerCode);
        return ;
    }
    BookIndex = GetPosition(bookCode, &returnBook); //��λ���ĵ�ͼ��
    readerIndex = GetRdPosition(readerCode, &returnReader);//��λ������
    borrowIndex = GetBRPosition(bookCode, readerCode, &returnRecord);
    if(borrowIndex == (-1))
    {
        printf("���Ϊ%s�Ķ���û�н���Ϊ%s��ͼ����δ���ļ�¼���޷����飡\n", readerCode, bookCode);
        return ;
    }
    if(fpBook = fopen("bookinfo.dat", "rb+") == NULL)
    {
        printf("�����޷���ͼ����Ϣ�ļ���\n");
        return ;
    }
    if(fpReader = fopen("readerinfo.dat", "rb+") == NULL)
    {
        printf("�����޷��򿪶�����Ϣ�ļ���\n");
        return ;
    }
    if(fpBorrow = fopen("borrowinfo.dat", "rb+") == NULL)
    {
        printf("�����޷��򿪽�����Ϣ�ļ���\n");
        return ;
    }
    returnBook.borrowNum--;
    returnReader.borrowBookNum--;
    time_t t = time(NULL);
    strcpy(returnRecord.borrowDate, ctime(&t));
    strcpy(returnRecord.borrowHandler, handler);
    returnRecord.bookStatus = '1';
    fseek(fpBook, (long)BOOKLEN * BookIndex, SEEK_SET); //��д��ͼ����ѽ������
    fwrite(&returnBook, BOOKLEN, 1, fpBook);
    fseek(fpReader, (long)READERLEN * readerIndex, SEEK_SET);   //��д�����˵��ѽ���ͼ����
    fwrite(&returnReader, READERLEN, 1, fpReader);
    fseek(fpBorrow, BORROWLEN * borrowIndex, SEEK_SET); //��дͼ����ļ�¼
    fwrite(&returnRecord, BORROWLEN, 1, fpBorrow);
    fclose(fpBook);
    fclose(fpReader);
    fclose(fpBorrow);
    printf("����ɹ����س�����������\n");
    getchar();
    getchar();
}

#endif // BOOK_H_INCLUDED
