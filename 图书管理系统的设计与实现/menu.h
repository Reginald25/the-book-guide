#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "myhead.h"

int MainMenu(char *user)        //主菜单
{
    int m = 0;
    while(1)
    {
        system("cls");
        printf("\n     \t\t\t图书管理员：%s，请按提示选择\n\n", user);
        printf("      1-基本信息维护");
        printf("      2-借书与还书");
        printf("      3-信息统计与查询");
        printf("      0-退出系统");
        printf("\n\n请选择（0~3）：");
        scanf("%d", &m);
        if(m >= 0 && m <= 3)
            break;
        else
        {
            printf("\n选择错误，请在0~3之间选择\n");
            getchar();
            getchar();
        }
    }
    return m;
}

int CreateSubMenu1(char *user)//子菜单 基本信息维护
{
    int m = 0;
    while(1)
    {
        system("cls");
        printf("\n             \t\t\t图书管理员：%s，请按提示选择\n\n", user);
        printf("基本信息维护");
        printf("       借书与还书");
        printf("       信息统计与查询");
        printf("       退出系统\n\n");
        printf("1——新增图书信息\n");
        printf("2——修改图书信息\n");
        printf("3——删除图书信息\n");
        printf("4——增加读者信息\n");
        printf("5——修改读者信息\n");
        printf("6——删除读者\n");
        printf("0——返回上一级菜单\n");
        printf("\n请选择（0~6）：");
        scanf("%d", &m);
        if( m >= 0 && m <= 6)
            break;
        else
        {
            printf("\n选择错误，请在0~6之间选择\n");
            getchar();
            getchar();
        }
    }
    return m;
}

int CreateSubMenu2(char *user)      //子菜单 借书与还书
{
    int m = 0;
    while(1)
    {
        system("cls");
        printf("\n               \t\t\t图书管理员：%s，请按提示选择\n\n", user);
        printf("基本信息维护");
        printf("              借书与还书 ");
        printf("              信息统计与查询");
        printf("              退出系统\n\n");
        printf("                            1-借书\n");
        printf("                            2-还书");
        printf("                            0-返回上一级菜单");
        printf("请选择（0~2）：");
        scanf("%d", &m);
        if( m >= 0 && m <= 2 )
            break;
        else
        {
            printf("\n选择错误，请在0~2之间选择\n");
            getchar();
            getchar();
        }
    }
    return m;
}

int CreateSubMenu3(char *user)//子菜单 信息统计与查询
{
    int m = 0;
    while(1)
    {
        system("cls");
        printf("\n                      \t\t\t图书管理员：%s，请按提示选择\n\n", user);
        printf("基本信息维护");
        printf("            借书与还书");
        printf("            信息统计与查询");
        printf("            退出系统\n\n");
        printf("                            1-图书清单\n");
        printf("                            2-读者清单\n");
        printf("                            3-图书查询\n");
        printf("                            4-读者查询\n");
        printf("                            0-返回上一级菜单\n");
        printf("请选择（0~4）：");
        scanf("%d", &m);
        if( m >= 0 && m <= 4 )
            break;
        else
        {
            printf("\n选择错误，请在（0~4）之间选择\n");
            getchar();
            getchar();
        }
    }
    return m;
}
#endif // MENU_H_INCLUDED
