#include <stdio.h>
#include <stdlib.h>
#include "ALL.h"

char handler[20];       //��¼������Ա

int main()
{
    int menuId;
    if(!Login())
        exit(0);        //��¼��������3�Σ��˳�
    system("mode con cols = 130 lines = 40");
    while(1)
    {
        menuId = MainMenu(handler);
        if(menuId == 0)
        {
            printf("\n���������\n\n");
            break;
        }
        switch(menuId)      //���ݲ˵���ʾѡ��ͬ����
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
