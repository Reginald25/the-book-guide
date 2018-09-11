#ifndef ISEXIST_H_INCLUDED
#define ISEXIST_H_INCLUDED

#include "myhead.h"

int IsBookExist(char * ChkBookCode) //判断指定的图书在文件中是否存在
{
    struct BookInfo chkBook;
    int isExist = 0;
    FILE *fp;
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL )
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    while(fread(&chkBook, BOOKLEN, 1, fp))
        if(strcmp(chkBook.bookCode, ChkBookCode) == 0 && chkBook.isAvailable == '1')
        {
            isExist = 1;
            break;
        }
    fclose(fp);
    return isExist;
}

int IsReaderExist(char *readerCode)//判断是否存在某编号的读者
{
    struct ReaderInfo reader;
    int isExist = 0;
    FILE *fp;
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL )
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    while(fread(&reader, READERLEN, 1, fp))
    {
        if(strcmp(reader.readerCode, readerCode) == 0 && reader.isAvailable == '1' )
        {
            isExist = 1;
            break;
        }
    }
    fclose(fp);
    return isExist;
}

#endif // ISEXIST_H_INCLUDED
