#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include "myhead.h"

//��¼ϵͳ
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
        printf("�������û�����");
        scanf("%s", loginName);
        printf("���������룺");
        i = 0;
        while((psw[i] = getchar()) != '\n')//���벢��������
        {
            if(psw[i] == 13 )
                break;
            if(psw[i] != '\b')//���˸����ʾ*��
            {
                printf("*");
                i++;
            }
            else                //�˸������ǰһ��
            {
                printf("\b \b");
                i--;
            }
        }
        psw[i] = '\0';
        fseek(fp, 0, SEEK_SET);
        while(fread(&user, LOGINLEN, 1, fp))//�����������û���������ƥ����û�
            if(!strcmp(user.loginName, loginName) && !strcmp(user.password, psw))
            {
                fclose(fp);
                strcpy(handler, loginName);
                return 1;
            }
            printf("\n�û��������벻��ȷ�����������룡 \n");
            wrongNum++;
    }
    printf("��¼����3�Σ��˳�ϵͳ��\n");
    return 0;
}
#endif // LOGIN_H_INCLUDED
