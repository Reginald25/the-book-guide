#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include "myhead.h"

//登录系统
int Login()
{
    struct LoginInfo user;
    char loginName[20], psw[20];
    int wrongNum = 0, i;
    FILE *fp;
    if((fp = fopen("login.dat", "rb")) == NULL )
        return 0;
    while(wrongNum < 3)
    {
        printf("请输入用户名：");
        scanf("%s", loginName);
        printf("请输入密码：");
        i = 0;
        while((psw[i] = getchar()) != '\n')//输入并隐藏密码
        {
            if(psw[i] == 13 )
                break;
            if(psw[i] != '\b')//非退格键显示*号
            {
                printf("*");
                i++;
            }
            else                //退格键则往前一格
            {
                printf("\b \b");
                i--;
            }
        }
        psw[i] = '\0';
        fseek(fp, 0, SEEK_SET);
        while(fread(&user, LOGINLEN, 1, fp))//查找与输入用户名及密码匹配的用户
            if(!strcmp(user.loginName, loginName) && !strcmp(user.password, psw))
            {
                fclose(fp);
                strcpy(handler, loginName);
                return 1;
            }
            printf("\n用户名或密码不正确，请重新输入！ \n");
            wrongNum++;
    }
    printf("登录错误3次，退出系统！\n");
    return 0;
}
#endif // LOGIN_H_INCLUDED
