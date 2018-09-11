#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include <myhead.h>

void SearchBook()//��ʾָ����ŵ�ͼ����Ϣ
{
    char bookCode[10];
    struct BookInfo chkBook;
    if(CountBook() == 0)
    {
        printf("����û��ͼ����Ϣ���޷����в�ѯ������\n");
        return ;
    }
    printf("*******ͼ����Ϣ��ѯ******\n");
    printf("�������ѯ��ͼ���ţ�");
    scanf("%s", bookCode);
    if(!IsBookExist(bookCode))
    {
        printf("���Ϊ%s��ͼ�鲻���ڣ���˲飡\n", bookCode);
        return ;
    }
    GetPosition(bookCode, &chkBook);
    printf("���Ϊ%s��ͼ����ϸ��Ϣ\n", bookCode);
    printf("--------------------------------------\n");
    printf("       ������\t%s\n", chkBook.bookName);
    printf("       ���ߣ�\t%s\n", chkBook.author);
    printf("       �۸�\t%.2f\n", chkBook.price);
    printf("       �����磺\t%s\n", chkBook.press);
    printf("       �������ڣ�\t%s\n", chkBook.publicationDate);
    getchar();
    getchar();
}

void SearchReader()//��ʾ������Ϣ�����н���ͼ�飬����ʾ��������ͼ�����Ϣ
{
    char readerCode[10];
    struct BorrowInfo borrowRecord;
    if(CountReader() == 0)
    {
        printf("ϵͳ���޶�����Ϣ���޷����в�ѯ������\n");
        return ;
    }
    printf("******������Ϣ��ѯ******\n");
    printf("�������ѯ�Ķ��߱�ţ�");
    scanf("%s", readerCode);
    if(!IsBookExist(readerCode))
    {
        printf("���Ϊ%s�Ķ��߲����ڣ���˲飡\n", readerCode);
        return ;
    }
    ShowAReader(readerCode);
    if(IsBorrowed(readerCode) == 0)
    {
        printf("    �ö���û�н���δ�黹��ͼ��\n");
    }
    else
    {
        printf("    �ö��߹�����%d��ͼ�飬��Ϣ���£�\n", IsBorrowed(readerCode));
        FILE *fp;
        if((fp = fopen("borrowinfo.dat", "rb+")) == NULL)
        {
            printf("���ļ�����\n");
            exit(0);
        }
        int i = 0;
        while(fread(&borrowRecord, BORROWLEN, 1, fp))
        {
            if(strcmp(borrowRecord.readerCode, readerCode) == 0 && borrowRecord.bookStatus == '0')
            {
                i++;
                printf("%d.   ͼ���ţ�% -10s, �������ڣ�% -10s, ����Ա��% -10s\n", i, borrowRecord.bookCode, borrowRecord.borrowDate, borrowRecord.borrowHandler);
            }
        }
        fclose(fp);
    }
    getchar();
    getchar();
}


#endif // SEARCH_H_INCLUDED
