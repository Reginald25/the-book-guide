#ifndef ISBORROW_H_INCLUDED
#define ISBORROW_H_INCLUDED

#include "myhead.h"

int IsBorrowOut( char *bookCode )//�ж�ĳ��ŵ�ͼ���Ƿ񱻽���
{
    struct BookInfo chkBook;
    int isBorrowOut = 0;
    FILE *fp;
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    while(fread(&chkBook, BOOKLEN, 1, fp))
        if(strcmp(chkBook.bookCode, bookCode) == 0 && chkBook.totalNum == chkBook.borrowNum)
        {
            isBorrowOut = 1;
            break;
        }
    fclose(fp);
    return isBorrowOut;
}

int IsBorrow(char *bookCode)//�ж�ĳ��ŵ�ͼ���Ƿ��б����
{
    struct BookInfo chkBook;
    int isBookBorrow = 0;
    FILE *fp;
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    while(fread(&chkBook, BOOKLEN, 1, fp))
    {
        if(strcmp(chkBook.bookCode, bookCode) == 0)
        {
            isBookBorrow = chkBook.borrowNum;
            break;
        }
    }
    fclose(fp);
    return isBookBorrow;
}

int IsBorrowed(char *readerCode)//���ض����ж����ڽ��ͼ��
{
    struct ReaderInfo reader;
    int borrowNum = 0;
    FILE *fp;
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    while(fread(&reader, READERLEN, 1, fp))
        if(strcmp(reader.readerCode, readerCode) == 0)
            borrowNum = reader.borrowBookNum;
    fclose(fp);
    return borrowNum;
}



#endif // ISBORROW_H_INCLUDED
