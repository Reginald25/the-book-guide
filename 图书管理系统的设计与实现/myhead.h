#ifndef MYHEAD_H_INCLUDED
#define MYHEAD_H_INCLUDED

#define BOOKLEN sizeof( struct BookInfo )
#define READERLEN sizeof( struct ReaderInfo )
#define BORROWLEN sizeof( struct BorrowInfo )
#define LOGINLEN sizeof( struct LoginInfo )

//���Ͷ���
struct BookInfo//ͼ����Ϣ����
{
    char bookCode[10];      //ͼ����
    char bookName[50];      //����
    char author[20];        //������
    float price;            //ͼ��۸�
    char press[50];         //������
    char publicationDate[50];  //��������
    char isAvailable;
    int totalNum;           //����Ĺݲ�����
    int borrowNum;          //�����ͼ����
};

struct ReaderInfo           //������Ϣ����
{
    char readerCode[10];        //���߱��
    char readerName[20];        //��������
    char sex[3];                //�����Ա�
    char isAvailable;           //����״̬����ʾ�����Ƿ���Ч
    int couldBorrowNum;         //�����ܽ�����
    int borrowBookNum;          //�����ѽ�����
};

struct BorrowInfo       //������Ϣ����
{
    char bookCode[10];      //ͼ����
    char readerCode[10];        //���߱��
    char borrowHandler[20];     //�������Ա
    char borrowDate[50];        //���ʱ��
    char returnHandler[20];     //�������Ա
    char returnDate[50];        //����ʱ��
    char bookStatus;            //����״̬��ֻ��¼�ѻ���δ����0Ϊδ��
};

struct LoginInfo        //��¼��Ϣ����
{
    char loginName[20];     //�û���
    char password[20];      //����
};

//��������
int Login();        //��¼��֤
void SubMenu1();    //�Ӳ˵����� ������Ϣά��
void SubMenu2();    //�Ӳ˵����� �����뻹�����
void SubMenu3();    //�Ӳ˵����� ��Ϣͳ�����ѯ
void AddBook();     //����ͼ��
void ModifyBookInfo();  //�޸�ͼ����Ϣ
void DelBook();     //ɾ��ͼ��
void AddReader();   //���Ӷ���
void ModifyReaderInfo();    //�޸Ķ�����Ϣ
void DelReader();       //ɾ������
void BookBorrow();      //�������
void BookReturn();      //�������
void ShowBookInfo();    //��ʾͼ����Ϣ
void ShowReaderInfo();  //��ʾ������Ϣ
void SearchBook();      //����ͼ��
void SearchReader();    //���Ҷ��߽�����Ϣ
void ShowAReader(char *);   //���ظ����Ķ�����Ϣ
int CountBook();            //����ͼ��������ͬһͼ����ֻ��һ��
int CountReader();      //������Ч��������
int IsBookExist(char *);    //�ж�ͼ���Ƿ����
int IsReaderExist(char *);  //�ж϶����Ƿ����
int CouldBorrow(char *);        //�ж϶����Ƿ��ܽ���
int CheckPrice(char *);     //�������ļ۸��Ƿ�Ϸ�
float ConvertToFloat(char *);       //�ַ���תΪ������
int IsBorrow(char *);       //�ж�ͼ���Ƿ��н��
int IsBorrowOut(char *);        //�ж�ͼ���Ƿ����
int IsBorrowed(char *); //�ж϶����Ƿ��н���δ��
int GetPosition(char *, struct BookInfo *); //����ͼ�����ļ��е�λ��
int GetRdPosition(char *, struct ReaderInfo *); //���ض������ļ��е�λ��
int GetBRPosition(char *, char *, struct BorrowInfo *); //����ĳ��������ĳ�����ļ��е�λ��
int MainMenu();         //���˵���ʾ
int CreateSubMenu1();       //�Ӳ˵���ʾ ������Ϣά��
int CreateSubMenu2();       //�Ӳ˵���ʾ �����뻹�����
int CreateSubMenu3();       //�Ӳ˵���ʾ ��Ϣͳ�����ѯ

#endif // MYHEAD_H_INCLUDED
