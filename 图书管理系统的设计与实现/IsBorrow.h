#ifndef ISBORROW_H_INCLUDED
#define ISBORROW_H_INCLUDED

#include "myhead.h"

int IsBorrowOut( char *bookCode )//判断某编号的图书是否被借完
{
    struct BookInfo chkBook;
    int isBorrowOut = 0;
    FILE *fp;
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
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

int IsBorrow(char *bookCode)//判断某编号的图书是否有被借出
{
    struct BookInfo chkBook;
    int isBookBorrow = 0;
    FILE *fp;
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
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

int IsBorrowed(char *readerCode)//返回读者有多少在借的图书
{
    struct ReaderInfo reader;
    int borrowNum = 0;
    FILE *fp;
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    while(fread(&reader, READERLEN, 1, fp))
        if(strcmp(reader.readerCode, readerCode) == 0)
            borrowNum = reader.borrowBookNum;
    fclose(fp);
    return borrowNum;
}



#endif // ISBORROW_H_INCLUDED
