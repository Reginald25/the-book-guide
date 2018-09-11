#ifndef DEL_H_INCLUDED
#define DEL_H_INCLUDED

#include "myhead.h"

void DelBook()//ɾ��ͼ���¼��ɾ��ͼ��ʱ���ı��ļ��м�¼��״̬
{
    struct BookInfo delBook;
    FILE *fp;
    char delBookCode[10];
    int delIndex;       //��ɾ����ͼ�����ļ��е�λ��
    if(CountBook() == 0)
    {
        printf("����û��ͼ����Ϣ���޷�ɾ��ͼ�飡\n");
        return ;
    }
    printf("\n******ɾ��ͼ��******\n");
    printf("      �������ɾ����ͼ���ţ�");
    scanf("%s", delBookCode);
    if(!IsBookExist(delBookCode))
    {
        printf("���Ϊ%s��ͼ�鲻���ڣ���˲飡\n", delBookCode);
        return ;
    }
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    delIndex = GetPosition(delBookCode, &delBook);
    delBook.isAvailable = '0';          //ɾ��ͼ����ı�ó�Ա��ֵ
    fseek(fp, (long)BOOKLEN * delIndex, SEEK_SET);
    fwrite(&delBook, BOOKLEN, 1, fp);
    fclose(fp);
    printf("ͼ��ɾ���ɹ�������ͼ��%d�ᣨ�س���������\n", CountBook());
    getchar();
    getchar();
}

void DelReader()//ɾ�����߼�¼
{
    struct ReaderInfo delReader;
    FILE *fp;
    char delReaderCode[10];
    int borrowNum;
    int delIndex;
    if(CountReader() == 0)
    {
        printf("����û�ж�����Ϣ���޷�ִ��ɾ����\n");
        return ;
    }
    printf("\n******ɾ������******\n");
    printf("      ������ɾ���Ķ��߱�ţ�");
    scanf("%s", delReaderCode);
    if(!IsReaderExist(delReaderCode))
    {
        printf("���Ϊ%s�Ķ��߲����ڣ���˲飡\n", delReaderCode);
        return ;
    }
    borrowNum = IsBorrowed(delReaderCode);
    if(borrowNum)
    {
        printf("���Ϊ%s�Ķ�����%d��ͼ�����δ��������ɾ����\n", delReaderCode, borrowNum);
        return ;
    }
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    delIndex = GetRdPosition(delReaderCode, &delReader);
    delReader.isAvailable = '0';
    fseek(fp, (long)READERLEN * delIndex, SEEK_SET);
    fwrite(&delReader, READERLEN, 1, fp);
    fclose(fp);
    printf("ɾ�����߼�¼�ɹ������ж���%d�ˣ��س���ɾ����\n", CountReader());
    getchar();
    getchar();
}

#endif // DEL_H_INCLUDED
