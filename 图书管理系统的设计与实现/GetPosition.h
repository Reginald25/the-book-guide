#ifndef GETPOSITION_H_INCLUDED
#define GETPOSITION_H_INCLUDED

#include "myhead.h"

int GetPosition(char *bookCode, struct BookInfo *chkBook)//获得图书记录在文件中的位置
{
    int count = 0;
    FILE *fp;
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    while(fread(chkBook, BOOKLEN, 1, fp))
    {
        if(strcmp(chkBook->bookCode, bookCode) == 0 && chkBook->isAvailable == '1')
        {
            fclose(fp);
            return count;
        }
        count++;
    }
    fclose(fp);
    return -1;
}

int GetBRPosition(char *bookCode, char *readerCode, struct BorrowInfo *borrowRecord)
{
    int count = 0;
    FILE *fp;
    if((fp = fopen("borrowinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    while(fread(borrowRecord, BORROWLEN, 1, fp))
    {
        if(strcmp(borrowRecord->bookCode, bookCode) == 0 && strcmp(borrowRecord->readerCode, readerCode) == 0 && borrowRecord->bookStatus == '0')
            return count;
        count++;
    }
    fclose(fp);
    return -1;
}

int GetRdPosition(char *readerCode, struct ReaderInfo *chkReader)
{
    int count = 0;
    FILE *fp;
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    while(fread(chkReader, READERLEN, 1, fp))
    {
        if(strcmp(chkReader->readerCode, readerCode) == 0 && chkReader->isAvailable == '1')
            return count;
        count++;
    }
    fclose(fp);
    return -1;
}

#endif // GETPOSITION_H_INCLUDED
