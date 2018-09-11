#ifndef DEL_H_INCLUDED
#define DEL_H_INCLUDED

#include "myhead.h"

void DelBook()//删除图书记录，删除图书时仅改变文件中记录的状态
{
    struct BookInfo delBook;
    FILE *fp;
    char delBookCode[10];
    int delIndex;       //欲删除的图书在文件中的位置
    if(CountBook() == 0)
    {
        printf("库中没有图书信息，无法删除图书！\n");
        return ;
    }
    printf("\n******删除图书******\n");
    printf("      请输入待删除的图书编号：");
    scanf("%s", delBookCode);
    if(!IsBookExist(delBookCode))
    {
        printf("编号为%s的图书不存在，请核查！\n", delBookCode);
        return ;
    }
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    delIndex = GetPosition(delBookCode, &delBook);
    delBook.isAvailable = '0';          //删除图书仅改变该成员的值
    fseek(fp, (long)BOOKLEN * delIndex, SEEK_SET);
    fwrite(&delBook, BOOKLEN, 1, fp);
    fclose(fp);
    printf("图书删除成功，现有图书%d册（回车键继续）\n", CountBook());
    getchar();
    getchar();
}

void DelReader()//删除读者记录
{
    struct ReaderInfo delReader;
    FILE *fp;
    char delReaderCode[10];
    int borrowNum;
    int delIndex;
    if(CountReader() == 0)
    {
        printf("库中没有读者信息，无法执行删除！\n");
        return ;
    }
    printf("\n******删除读者******\n");
    printf("      输入欲删除的读者编号：");
    scanf("%s", delReaderCode);
    if(!IsReaderExist(delReaderCode))
    {
        printf("编号为%s的读者不存在，请核查！\n", delReaderCode);
        return ;
    }
    borrowNum = IsBorrowed(delReaderCode);
    if(borrowNum)
    {
        printf("编号为%s的读者有%d册图书借阅未还，不可删除！\n", delReaderCode, borrowNum);
        return ;
    }
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    delIndex = GetRdPosition(delReaderCode, &delReader);
    delReader.isAvailable = '0';
    fseek(fp, (long)READERLEN * delIndex, SEEK_SET);
    fwrite(&delReader, READERLEN, 1, fp);
    fclose(fp);
    printf("删除读者记录成功，现有读者%d人（回车键删除）\n", CountReader());
    getchar();
    getchar();
}

#endif // DEL_H_INCLUDED
