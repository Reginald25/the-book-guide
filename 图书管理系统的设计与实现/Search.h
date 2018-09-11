#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include <myhead.h>

void SearchBook()//显示指定编号的图书信息
{
    char bookCode[10];
    struct BookInfo chkBook;
    if(CountBook() == 0)
    {
        printf("库中没有图书信息，无法进行查询操作！\n");
        return ;
    }
    printf("*******图书信息查询******\n");
    printf("输入待查询的图书编号：");
    scanf("%s", bookCode);
    if(!IsBookExist(bookCode))
    {
        printf("编号为%s的图书不存在，请核查！\n", bookCode);
        return ;
    }
    GetPosition(bookCode, &chkBook);
    printf("编号为%s的图书详细信息\n", bookCode);
    printf("--------------------------------------\n");
    printf("       书名：\t%s\n", chkBook.bookName);
    printf("       作者：\t%s\n", chkBook.author);
    printf("       价格：\t%.2f\n", chkBook.price);
    printf("       出版社：\t%s\n", chkBook.press);
    printf("       出版日期：\t%s\n", chkBook.publicationDate);
    getchar();
    getchar();
}

void SearchReader()//显示读者信息，若有借阅图书，则还显示其所借阅图书的信息
{
    char readerCode[10];
    struct BorrowInfo borrowRecord;
    if(CountReader() == 0)
    {
        printf("系统中无读者信息，无法进行查询操作！\n");
        return ;
    }
    printf("******读者信息查询******\n");
    printf("输入待查询的读者编号：");
    scanf("%s", readerCode);
    if(!IsBookExist(readerCode))
    {
        printf("编号为%s的读者不存在，请核查！\n", readerCode);
        return ;
    }
    ShowAReader(readerCode);
    if(IsBorrowed(readerCode) == 0)
    {
        printf("    该读者没有借阅未归还的图书\n");
    }
    else
    {
        printf("    该读者共借阅%d册图书，信息如下：\n", IsBorrowed(readerCode));
        FILE *fp;
        if((fp = fopen("borrowinfo.dat", "rb+")) == NULL)
        {
            printf("打开文件错误！\n");
            exit(0);
        }
        int i = 0;
        while(fread(&borrowRecord, BORROWLEN, 1, fp))
        {
            if(strcmp(borrowRecord.readerCode, readerCode) == 0 && borrowRecord.bookStatus == '0')
            {
                i++;
                printf("%d.   图书编号：% -10s, 借阅日期：% -10s, 管理员：% -10s\n", i, borrowRecord.bookCode, borrowRecord.borrowDate, borrowRecord.borrowHandler);
            }
        }
        fclose(fp);
    }
    getchar();
    getchar();
}


#endif // SEARCH_H_INCLUDED
