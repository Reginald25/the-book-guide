#ifndef ISEXIST_H_INCLUDED
#define ISEXIST_H_INCLUDED

#include "myhead.h"

int IsBookExist(char * ChkBookCode) //�ж�ָ����ͼ�����ļ����Ƿ����
{
    struct BookInfo chkBook;
    int isExist = 0;
    FILE *fp;
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL )
    {
        printf("���ļ�����\n");
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

int IsReaderExist(char *readerCode)//�ж��Ƿ����ĳ��ŵĶ���
{
    struct ReaderInfo reader;
    int isExist = 0;
    FILE *fp;
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL )
    {
        printf("���ļ�����\n");
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
