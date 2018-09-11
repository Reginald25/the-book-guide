#ifndef MYHEAD_H_INCLUDED
#define MYHEAD_H_INCLUDED

#define BOOKLEN sizeof( struct BookInfo )
#define READERLEN sizeof( struct ReaderInfo )
#define BORROWLEN sizeof( struct BorrowInfo )
#define LOGINLEN sizeof( struct LoginInfo )

//类型定义
struct BookInfo//图书信息定义
{
    char bookCode[10];      //图书编号
    char bookName[50];      //书名
    char author[20];        //作者名
    float price;            //图书价格
    char press[50];         //出版社
    char publicationDate[50];  //出版日期
    char isAvailable;
    int totalNum;           //本书的馆藏总数
    int borrowNum;          //借出的图书数
};

struct ReaderInfo           //读者信息定义
{
    char readerCode[10];        //读者编号
    char readerName[20];        //读者姓名
    char sex[3];                //读者性别
    char isAvailable;           //读者状态，表示读者是否有效
    int couldBorrowNum;         //读者能借书数
    int borrowBookNum;          //读者已借书数
};

struct BorrowInfo       //借阅信息定义
{
    char bookCode[10];      //图书编号
    char readerCode[10];        //读者编号
    char borrowHandler[20];     //借书操作员
    char borrowDate[50];        //借出时间
    char returnHandler[20];     //还书操作员
    char returnDate[50];        //还书时间
    char bookStatus;            //借书状态，只记录已还、未还、0为未还
};

struct LoginInfo        //登录信息定义
{
    char loginName[20];     //用户名
    char password[20];      //密码
};

//函数声明
int Login();        //登录验证
void SubMenu1();    //子菜单处理 基本信息维护
void SubMenu2();    //子菜单处理 借书与还书管理
void SubMenu3();    //子菜单处理 信息统计与查询
void AddBook();     //增加图书
void ModifyBookInfo();  //修改图书信息
void DelBook();     //删除图书
void AddReader();   //增加读者
void ModifyReaderInfo();    //修改读者信息
void DelReader();       //删除读者
void BookBorrow();      //借书操作
void BookReturn();      //还书操作
void ShowBookInfo();    //显示图书信息
void ShowReaderInfo();  //显示读者信息
void SearchBook();      //搜索图书
void SearchReader();    //查找读者借书信息
void ShowAReader(char *);   //返回给定的读者信息
int CountBook();            //计算图书总数，同一图书编号只记一次
int CountReader();      //计算有效读者人数
int IsBookExist(char *);    //判断图书是否存在
int IsReaderExist(char *);  //判断读者是否存在
int CouldBorrow(char *);        //判断读者是否还能借书
int CheckPrice(char *);     //检查输入的价格是否合法
float ConvertToFloat(char *);       //字符串转为浮点数
int IsBorrow(char *);       //判断图书是否有借出
int IsBorrowOut(char *);        //判断图书是否借完
int IsBorrowed(char *); //判断读者是否有借书未还
int GetPosition(char *, struct BookInfo *); //返回图书在文件中的位置
int GetRdPosition(char *, struct ReaderInfo *); //返回读者在文件中的位置
int GetBRPosition(char *, char *, struct BorrowInfo *); //返回某读者所借某书在文件中的位置
int MainMenu();         //主菜单显示
int CreateSubMenu1();       //子菜单显示 基本信息维护
int CreateSubMenu2();       //子菜单显示 借书与还书管理
int CreateSubMenu3();       //子菜单显示 信息统计与查询

#endif // MYHEAD_H_INCLUDED
