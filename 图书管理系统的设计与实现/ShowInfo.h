#ifndef SHOWINFO_H_INCLUDED
#define SHOWINFO_H_INCLUDED

#include "myhead.h"

void ShowBookInfo()//显示所有图书的信息
{
    struct BookInfo book;
    FILE *fp;
    int booknum = CountBook();
    if(booknum == 0)
    {
        printf("库中没有图书信息！\n");
        return;
    }
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    printf("\n  编号      书名      作者      价格      出版社     出版日期        库存数     已借出\n");
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

void ShowReaderInfo()//显示所有读者的信息
{
    struct ReaderInfo reader;
    FILE *fp;
    int readerNum = CountReader();
    if(readerNum == 0)
    {
        printf("库中没有读者信息！\n");
        return ;
    }
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    printf("\n  读者编号    姓名    性别    借书限额数    已借书数\n");
    while(fread(&reader, READERLEN, 1, fp))
        if(reader.isAvailable == '1')
            printf("% -7s% -11s% -5s%  -8d%   -10d\n", reader.readerCode, reader.readerName, reader.sex, reader.couldBorrowNum, reader.borrowBookNum);
    fclose(fp);
    getchar();
    getchar();
}

void ShowAReader(char *readerCode)//显示指定编号的读者详细信息
{
    struct ReaderInfo chkReader;
    FILE *fp;
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    while(fread(&chkReader, READERLEN, 1, fp))
        if(strcmp(chkReader.readerCode, readerCode) == 0)
            break;
    printf("  读者：\t%s(%s----%s)\n", readerCode, chkReader.readerName,chkReader.sex);
    fclose(fp);
}

#endif // SHOWINFO_H_INCLUDED
