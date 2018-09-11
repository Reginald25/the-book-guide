#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED

#include "myhead.h"

void AddBook()//新图书入库
{
    struct BookInfo newBook;
    FILE *fp;
    char price[20];
    printf("\n *************************新入库图书（按提示录入信息）************************* \n");
    printf("      图书编号（<=9个字符）：");
    scanf("%s", newBook.bookCode );
    while(IsBookExist(newBook.bookCode))
    {
        printf("新增的图书编号%s已经存在，重新输入！\n", newBook.bookCode);
        printf("      图书编号（<=9个字符）：");
        scanf("%s", newBook.bookCode);
    }
    printf("     书名：");
    scanf("%s", newBook.bookName);
    printf("     作者：");
    scanf("%s", newBook.author);
    printf("     书价");
    scanf("%s", price);
    while(! CheckPrice(price))//输入价格字符串是否正确
    {
        printf("输入价格不合法！重新输入！\n");
        printf("     书价");
        scanf("%s", price);
    }
    newBook.price = ConvertToFloat(price);
    printf("     出版社：");
    scanf("%s", newBook.press);
    printf("     出版日期（YYYY-MM）：");
    scanf("%s", newBook.publicationDate);
    printf("     入库数：");
    scanf("%d", &newBook.totalNum);
    newBook.borrowNum = 0;
    newBook.isAvailable = '1';
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    fseek(fp, 0, SEEK_END);
    fwrite(&newBook, BOOKLEN, 1, fp);
    fclose(fp);
    printf("新增图书成功，现有图书%d册（回车键继续）\n", CountBook());
    getchar();
    getchar();
}

void AddReader()//新增读者管理
{
    struct ReaderInfo newReader;
    FILE *fp;
    printf("\n******新增读者（按提示输入信息）******\n");
    printf("    读者编号（<= 10个字符）：");
    scanf("%s", newReader.readerCode);
    while(IsReaderExist(newReader.readerCode))
    {
        printf("新增的读者编号%s已经存在，重新输入！\n", newReader.readerCode);
        printf("      读者编号（<=10个字符）：");
        scanf("%s", newReader.readerCode);
    }
    printf("      读者姓名：");
    scanf("%s", newReader.readerName);
    printf("      性别：");
    scanf("%s", newReader.sex);
    newReader.isAvailable = '1';
    printf("      借书限额：");
    scanf("%d", &newReader.couldBorrowNum);
    newReader.borrowBookNum = 0;
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    fseek(fp, 0, SEEK_END);
    fwrite(&newReader, READERLEN, 1, fp);
    fclose(fp);
    printf("新增读者成功，现有读者%d人（回车键继续）\n", CountReader());
    getchar();
    getchar();
}

#endif // ADD_H_INCLUDED
