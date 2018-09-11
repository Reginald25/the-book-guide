#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include "myhead.h"

void BookBorrow()//借书管理
{
    struct BookInfo borrowBook;
    struct BorrowInfo borrowRecord;
    struct ReaderInfo borrowReader;
    FILE *fpBook, *fpReader, *fpBorrow;
    char bookCode[10];
    char readerCode[10];
    int bookIndex = 0, readerIndex = 0;
    printf("******借书管理******\n");
    scanf("%s", bookCode);
    if(! IsBookExist(bookCode))
    {
        printf("编号为%s的图书不存在，借阅失败！\n", bookCode);
        return ;
    }
    if(IsBorrowOut(bookCode))
    {
        printf("编号为%s的图书已被全部借出，借阅失败！\n", bookCode);
        return ;
    }
    printf("输入读者编号：");
    scanf("%s", readerCode);
    if(!IsReaderExist(readerCode))
    {
        printf("编号为%s的读者不存在，借阅失败!\n", readerCode);
        return ;
    }
    if(!CouldBorrow(readerCode))
    {
        printf("编号为%s的读者借书数已满，请还书后再借!\n", readerCode);
        return ;
    }
    if((fpBook = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("错误：无法打开读者信息文件！\n");
        return ;
    }
    if((fpBorrow = fopen("borrowinfo.dat", "rb+")) == NULL)
    {
        printf("错误：无法打开借书信息文件！\n");
        return ;
    }
    bookIndex = GetPosition(bookCode, &borrowBook);         //定位借阅的图书
    readerIndex = GetRdPosition(readerCode, &borrowReader);     //定位借书人
    borrowBook.borrowNum = borrowBook.borrowNum + 1;
    borrowReader.borrowBookNum = borrowReader.borrowBookNum + 1;
    strcpy(borrowRecord.bookCode, bookCode);
    strcpy(borrowRecord.readerCode, readerCode);
    time_t t = time(NULL);
    strcpy(borrowRecord.borrowDate, ctime(&t));
    strcpy(borrowRecord.borrowHandler, handler);
    borrowRecord.bookStatus = '0';
    fseek(fpBook, (long)BOOKLEN * bookIndex, SEEK_SET);         //改写该图书的已借出数量
    fwrite(&borrowBook, BOOKLEN, 1, fpBook);
    fseek(fpReader, (long)READERLEN * readerIndex, SEEK_SET);       //改写借书人的已借阅图书数
    fwrite(&borrowReader, READERLEN, 1, fpReader);
    fseek(fpBorrow, 0, SEEK_END);               //增加图书借阅记录
    fwrite(&borrowRecord, BORROWLEN, 1, fpBorrow);
    fclose(fpBook);
    fclose(fpReader);
    fclose(fpBorrow);
    printf("图书借阅成功（回车键继续）\n");
    getchar();
    getchar();
}

void BookReturn()//还书管理
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
        printf("库中没有图书或者读者信息，无法执行还书操作！\n");
        return ;
    }
    printf("******还书管理******\n");
    printf("      输入图书编号：");
    scanf("%s", bookCode);
    if(! IsBookExist(bookCode))
    {
        printf("编号为%s的图书不存在，还书失败！\n", bookCode);
        return ;
    }
    if(!IsBook(bookCode))
    {
        printf("编号为%s的图书未被借出，还书失败！\n", bookCode);
        return ;
    }
    printf("输入读者编号：");
    scanf("%s", readerCode);
    if(!IsReaderExist(readerCode))
    {
        printf("编号为%s的读者不存在，还书失败！\n", readerCode);
        return ;
    }
    if(!IsBorrowed(readerCode))
    {
        printf("编号为%s的读者没有借书记录，无法还书！\n", readerCode);
        return ;
    }
    BookIndex = GetPosition(bookCode, &returnBook); //定位借阅的图书
    readerIndex = GetRdPosition(readerCode, &returnReader);//定位借书人
    borrowIndex = GetBRPosition(bookCode, readerCode, &returnRecord);
    if(borrowIndex == (-1))
    {
        printf("编号为%s的读者没有借编号为%s的图书且未还的记录，无法还书！\n", readerCode, bookCode);
        return ;
    }
    if(fpBook = fopen("bookinfo.dat", "rb+") == NULL)
    {
        printf("错误：无法打开图书信息文件！\n");
        return ;
    }
    if(fpReader = fopen("readerinfo.dat", "rb+") == NULL)
    {
        printf("错误：无法打开读者信息文件！\n");
        return ;
    }
    if(fpBorrow = fopen("borrowinfo.dat", "rb+") == NULL)
    {
        printf("错误：无法打开借书信息文件！\n");
        return ;
    }
    returnBook.borrowNum--;
    returnReader.borrowBookNum--;
    time_t t = time(NULL);
    strcpy(returnRecord.borrowDate, ctime(&t));
    strcpy(returnRecord.borrowHandler, handler);
    returnRecord.bookStatus = '1';
    fseek(fpBook, (long)BOOKLEN * BookIndex, SEEK_SET); //改写该图书的已借出数量
    fwrite(&returnBook, BOOKLEN, 1, fpBook);
    fseek(fpReader, (long)READERLEN * readerIndex, SEEK_SET);   //改写借书人的已借阅图书数
    fwrite(&returnReader, READERLEN, 1, fpReader);
    fseek(fpBorrow, BORROWLEN * borrowIndex, SEEK_SET); //改写图书借阅记录
    fwrite(&returnRecord, BORROWLEN, 1, fpBorrow);
    fclose(fpBook);
    fclose(fpReader);
    fclose(fpBorrow);
    printf("还书成功（回车键继续）：\n");
    getchar();
    getchar();
}

#endif // BOOK_H_INCLUDED
