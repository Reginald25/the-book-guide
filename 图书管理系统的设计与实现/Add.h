#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED

#include "myhead.h"

void AddBook()//��ͼ�����
{
    struct BookInfo newBook;
    FILE *fp;
    char price[20];
    printf("\n *************************�����ͼ�飨����ʾ¼����Ϣ��************************* \n");
    printf("      ͼ���ţ�<=9���ַ�����");
    scanf("%s", newBook.bookCode );
    while(IsBookExist(newBook.bookCode))
    {
        printf("������ͼ����%s�Ѿ����ڣ��������룡\n", newBook.bookCode);
        printf("      ͼ���ţ�<=9���ַ�����");
        scanf("%s", newBook.bookCode);
    }
    printf("     ������");
    scanf("%s", newBook.bookName);
    printf("     ���ߣ�");
    scanf("%s", newBook.author);
    printf("     ���");
    scanf("%s", price);
    while(! CheckPrice(price))//����۸��ַ����Ƿ���ȷ
    {
        printf("����۸񲻺Ϸ����������룡\n");
        printf("     ���");
        scanf("%s", price);
    }
    newBook.price = ConvertToFloat(price);
    printf("     �����磺");
    scanf("%s", newBook.press);
    printf("     �������ڣ�YYYY-MM����");
    scanf("%s", newBook.publicationDate);
    printf("     �������");
    scanf("%d", &newBook.totalNum);
    newBook.borrowNum = 0;
    newBook.isAvailable = '1';
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    fseek(fp, 0, SEEK_END);
    fwrite(&newBook, BOOKLEN, 1, fp);
    fclose(fp);
    printf("����ͼ��ɹ�������ͼ��%d�ᣨ�س���������\n", CountBook());
    getchar();
    getchar();
}

void AddReader()//�������߹���
{
    struct ReaderInfo newReader;
    FILE *fp;
    printf("\n******�������ߣ�����ʾ������Ϣ��******\n");
    printf("    ���߱�ţ�<= 10���ַ�����");
    scanf("%s", newReader.readerCode);
    while(IsReaderExist(newReader.readerCode))
    {
        printf("�����Ķ��߱��%s�Ѿ����ڣ��������룡\n", newReader.readerCode);
        printf("      ���߱�ţ�<=10���ַ�����");
        scanf("%s", newReader.readerCode);
    }
    printf("      ����������");
    scanf("%s", newReader.readerName);
    printf("      �Ա�");
    scanf("%s", newReader.sex);
    newReader.isAvailable = '1';
    printf("      �����޶");
    scanf("%d", &newReader.couldBorrowNum);
    newReader.borrowBookNum = 0;
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    fseek(fp, 0, SEEK_END);
    fwrite(&newReader, READERLEN, 1, fp);
    fclose(fp);
    printf("�������߳ɹ������ж���%d�ˣ��س���������\n", CountReader());
    getchar();
    getchar();
}

#endif // ADD_H_INCLUDED
