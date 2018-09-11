#ifndef MODIFY_H_INCLUDED
#define MODIFY_H_INCLUDED

#include "myhead.h"

void ModifyBookInfo()//�޸�ͼ����Ϣ
{
    struct BookInfo modiBook;
    FILE *fp;
    char modiBookCode[10];
    char price[20];
    int modiIndex = 0;  //���޸�ͼ�����ļ��е�λ��
    printf("\n******�޸�ͼ����Ϣ******\n");
    printf("      ������Ҫ�޸ĵ�ͼ���ţ�");
    scanf("%s", modiBookCode);
    if(! IsBookExist(modiBookCode))
    {
        printf("���Ϊ%s��ͼ�鲻���ڣ���˲飡\n", modiBookCode);
        return ;
    }
    modiIndex = GetPosition(modiBookCode, &modiBook);
    printf("      ������");
    scanf("%s", modiBook.bookName);
    printf("      ���ߣ�");
    scanf("%s", modiBook.author);
    printf("      ��ۣ�");
    scanf("%s", price);
    while(! CheckPrice(price))//����ļ۸��ַ����Ƿ���ȷ
    {
        printf("����۸񲻺Ϸ����������룡\n");
        printf("      ��ۣ�");
        scanf("%s", price);
    }
    modiBook.price = ConvertToFloat(price);
    printf("      �����磺");
    scanf("%s", modiBook.press);
    printf("      �������ڣ�YYYY-MM����");
    scanf("%s", modiBook.publicationDate);
    printf("      �������");
    scanf("%d", &modiBook.totalNum);
    if((fp = fopen("bookinfo.dat", "rb+")) == NULL)
    {
        printf("�ļ��򿪴���\n");
        exit(0);
    }
    fseek(fp, (long)BOOKLEN * modiIndex, SEEK_SET);
    fwrite(&modiBook, BOOKLEN, 1, fp);
    fclose(fp);
    printf("ͼ����Ϣ�޸ĳɹ����س���������\n");
    getchar();
    getchar();
}

void ModifyReaderInfo()//�޸Ķ�����Ϣ
{
    struct ReaderInfo modiReader;
    FILE *fp;
    char modiReaderCode[10];
    int modiReaderIndex = 0;
    if(CountReader() == 0)
    {
        printf("����û�ж�����Ϣ���޷�ִ���޸ģ�\n");
        return ;
    }
    printf("\n******�޸Ķ�����Ϣ******\n");
    printf("      �������޸ĵĶ��߱�ţ�");
    scanf("%s", modiReaderCode);
    if(! IsReaderExist(modiReaderCode))
    {
        printf("���Ϊ%s�Ķ��߲����ڣ���˲飡\n", modiReaderCode);
        return ;
    }
    modiReaderIndex = GetRdPosition(modiReaderCode, &modiReader);
    printf("��������ʾ������Ϊ%s�Ķ�����Ϣ\n", modiReaderCode);
    printf("      ����������");
    scanf("%s", modiReader.readerName);
    printf("      �Ա�");
    scanf("%s", modiReader.sex);
    modiReader.isAvailable = '1';
    printf("      �����޶");
    scanf("%d", &modiReader.couldBorrowNum);
    if((fp = fopen("readerinfo.dat", "rb+")) == NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    fseek(fp, (long)READERLEN * modiReaderIndex, SEEK_SET);
    fwrite(&modiReader, READERLEN, 1, fp);
    fclose(fp);
    printf("�޸Ķ�����Ϣ�ɹ����س�����������\n");
    getchar();
    getchar();
}

#endif // MODIFY_H_INCLUDED
