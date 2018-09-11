#ifndef COULDBORROW_H_INCLUDED
#define COULDBORROW_H_INCLUDED

#include "myhead.h"

int CouldBorrow(char *readerCode)//���ض��߻��ܽ��������
{
    struct ReaderInfo reader;
    int couldBorrow = 0;
    FILE *fp;
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    while(fread(&reader, READERLEN, 1, fp))
    {
        if(strcmp(reader.readerCode, readerCode) == 0 && reader.couldBorrowNum > reader.borrowBook - Num)
        {
            couldBorrow = reader.couldBorrowNum - reader.borrowBookNum;
            break;
        }
    }
    fclose(fp);
    return couldBorrow;
}

#endif // COULDBORROW_H_INCLUDED
