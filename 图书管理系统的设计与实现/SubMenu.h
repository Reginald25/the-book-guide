#ifndef SUBMENU_H_INCLUDED
#define SUBMENU_H_INCLUDED

#include "myhead.h"

void SubMenu1()//基本信息维护
{
    int Menuld;
    while(1)
    {
        Menuld = CreateSubMenu1(handler);
        if(Menuld == 0)
            break;
        switch(Menuld)
        {
        case 1:
            AddBook();
            break;
        case 2:
            ModifyBookInfo();
            break;
        case 3:
            DelBook();
            break;
        case 4:
            AddReader();
            break;
        case 5:
            ModifyReaderInfo();
            break;
        case 6:
            DelReader();
            break;
        case 0:
            MainMenu(handler);
            break;
        }
    }
}

void SubMenu2()//借书与还书管理
{
    int Menuld;
    while(1)
    {
        Menuld = CreateSubMenu2(handler);
        if(Menuld == 0)
            break;
        switch(Menuld)
        {
        case 1:
            BookBorrow();
            break;
        case 2:
            BookReturn();
            break;
        case 0:
            MainMenu(handler);
            break;
        }
    }
}

void SubMenu3()//信息统计与查询
{
    int Menuld;
    while(1)
    {
        Menuld = CreateSubMenu3(handler);
        if(Menuld == 0)
            break;
        switch(Menuld)
        {
        case 1:
            ShowBookInfo();
            break;
        case 2:
            ShowReaderInfo();
            break;
        case 3:
            SearchBook();
            break;
        case 4:
            SearchReader();
            break;
        case 0:
            MainMenu(handler);
            break;
        }
    }
}
#endif // SUBMENU_H_INCLUDED
