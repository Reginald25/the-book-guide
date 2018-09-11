#ifndef MODIFY_H_INCLUDED
#define MODIFY_H_INCLUDED

#include "myhead.h"

void ModifyBookInfo()//修改图书信息
{
    struct BookInfo modiBook;
    FILE *fp;
    char modiBookCode[10];
    char price[20];
    int modiIndex = 0;  //欲修改图书在文件中的位置
    printf("\n******修改图书信息******\n");
    printf("      请输入要修改的图书编号：");
    scanf("%s", modiBookCode);
    if(! IsBookExist(modiBookCode))
    {
        printf("编号为%s的图书不存在，请核查！\n", modiBookCode);
        return ;
    }
    modiIndex = GetPosition(modiBookCode, &modiBook);
    printf("      书名：");
    scanf("%s", modiBook.bookName);
    printf("      作者：");
    scanf("%s", modiBook.author);
    printf("      书价：");
    scanf("%s", price);
    while(! CheckPrice(price))//输入的价格字符串是否正确
    {
        printf("输入价格不合法！重新输入！\n");
        printf("      书价：");
        scanf("%s", price);
    }
    modiBook.price = ConvertToFloat(price);
    printf("      出版社：");
    scanf("%s", modiBook.press);
    printf("      出版日期（YYYY-MM）：");
    scanf("%s", modiBook.publicationDate);
    printf("      库存数：");
    scanf("%d", &modiBook.totalNum);
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("文件打开错误！\n");
        exit(0);
    }
    fseek(fp, (long)BOOKLEN * modiIndex, SEEK_SET);
    fwrite(&modiBook, BOOKLEN, 1, fp);
    fclose(fp);
    printf("图书信息修改成功（回车键继续）\n");
    getchar();
    getchar();
}

void ModifyReaderInfo()//修改读者信息
{
    struct ReaderInfo modiReader;
    FILE *fp;
    char modiReaderCode[10];
    int modiReaderIndex = 0;
    if(CountReader() == 0)
    {
        printf("库中没有读者信息，无法执行修改！\n");
        return ;
    }
    printf("\n******修改读者信息******\n");
    printf("      输入欲修改的读者编号：");
    scanf("%s", modiReaderCode);
    if(! IsReaderExist(modiReaderCode))
    {
        printf("编号为%s的读者不存在，请核查！\n", modiReaderCode);
        return ;
    }
    modiReaderIndex = GetRdPosition(modiReaderCode, &modiReader);
    printf("按如下提示输入编号为%s的读者信息\n", modiReaderCode);
    printf("      读者姓名：");
    scanf("%s", modiReader.readerName);
    printf("      性别：");
    scanf("%s", modiReader.sex);
    modiReader.isAvailable = '1';
    printf("      借书限额：");
    scanf("%d", &modiReader.couldBorrowNum);
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    fseek(fp, (long)READERLEN * modiReaderIndex, SEEK_SET);
    fwrite(&modiReader, READERLEN, 1, fp);
    fclose(fp);
    printf("修改读者信息成功（回车键继续）：\n");
    getchar();
    getchar();
}

#endif // MODIFY_H_INCLUDED
