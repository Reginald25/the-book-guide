#ifndef SHOWINFO_H_INCLUDED
#define SHOWINFO_H_INCLUDED

#include "myhead.h"

void ShowBookInfo()//��ʾ����ͼ�����Ϣ
{
    struct BookInfo book;
    FILE *fp;
    int booknum = CountBook();
    if(booknum == 0)
    {
        printf("����û��ͼ����Ϣ��\n");
        return;
    }
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    printf("\n  ���      ����      ����      �۸�      ������     ��������        �����     �ѽ��\n");
    printf("----------------------------------------------------------------------------------------\n");
    while(fread(&book, BOOKLEN, 1, fp))
    {
        if(book.isAvailable == '1')
            printf("% -7s % -21s % -11s % -7.2f % -20s\t%10s  %5d   %3d\n", book.bookCode, book.bookName, book.author, book.price, book.press, book.publicationDate, book.totalNum, book.borrowNum);
    }
    fclose(fp);
    getchar();
    getchar();
}

void ShowReaderInfo()//��ʾ���ж��ߵ���Ϣ
{
    struct ReaderInfo reader;
    FILE *fp;
    int readerNum = CountReader();
    if(readerNum == 0)
    {
        printf("����û�ж�����Ϣ��\n");
        return ;
    }
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    printf("\n  ���߱��    ����    �Ա�    �����޶���    �ѽ�����\n");
    while(fread(&reader, READERLEN, 1, fp))
        if(reader.isAvailable == '1')
            printf("% -7s% -11s% -5s%  -8d%   -10d\n", reader.readerCode, reader.readerName, reader.sex, reader.couldBorrowNum, reader.borrowBookNum);
    fclose(fp);
    getchar();
    getchar();
}

void ShowAReader(char *readerCode)//��ʾָ����ŵĶ�����ϸ��Ϣ
{
    struct ReaderInfo chkReader;
    FILE *fp;
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    while(fread(&chkReader, READERLEN, 1, fp))
        if(strcmp(chkReader.readerCode, readerCode) == 0)
            break;
    printf("  ���ߣ�\t%s(%s----%s)\n", readerCode, chkReader.readerName,chkReader.sex);
    fclose(fp);
}

#endif // SHOWINFO_H_INCLUDED
