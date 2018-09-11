#include <stdio.h>
#include <stdlib.h>
#include "ALL.h"

char handler[20];       //记录操作人员

int main()
{
    int menuId;
    if(!Login())
        exit(0);        //登录连续错误3次，退出
    system("mode con cols = 130 lines = 40");
    while(1)
    {
        menuId = MainMenu(handler);
        if(menuId == 0)
        {
            printf("\n程序结束！\n\n");
            break;
        }
        switch(menuId)      //根据菜单提示选择不同操作
        {
        case 1:
            SubMenu1();
            break;
        case 2:
            SubMenu2();
            break;
        case 3:
            SubMenu3();
            break;
        }
    }
    return 0;
}
