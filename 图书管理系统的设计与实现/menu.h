#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "myhead.h"

int MainMenu(char *user)        //���˵�
{
    int m = 0;
    while(1)
    {
        system("cls");
        printf("\n     \t\t\tͼ�����Ա��%s���밴��ʾѡ��\n\n", user);
        printf("      1-������Ϣά��");
        printf("      2-�����뻹��");
        printf("      3-��Ϣͳ�����ѯ");
        printf("      0-�˳�ϵͳ");
        printf("\n\n��ѡ��0~3����");
        scanf("%d", &m);
        if(m >= 0 && m <= 3)
            break;
        else
        {
            printf("\nѡ���������0~3֮��ѡ��\n");
            getchar();
            getchar();
        }
    }
    return m;
}

int CreateSubMenu1(char *user)//�Ӳ˵� ������Ϣά��
{
    int m = 0;
    while(1)
    {
        system("cls");
        printf("\n             \t\t\tͼ�����Ա��%s���밴��ʾѡ��\n\n", user);
        printf("������Ϣά��");
        printf("       �����뻹��");
        printf("       ��Ϣͳ�����ѯ");
        printf("       �˳�ϵͳ\n\n");
        printf("1��������ͼ����Ϣ\n");
        printf("2�����޸�ͼ����Ϣ\n");
        printf("3����ɾ��ͼ����Ϣ\n");
        printf("4�������Ӷ�����Ϣ\n");
        printf("5�����޸Ķ�����Ϣ\n");
        printf("6����ɾ������\n");
        printf("0����������һ���˵�\n");
        printf("\n��ѡ��0~6����");
        scanf("%d", &m);
        if( m >= 0 && m <= 6)
            break;
        else
        {
            printf("\nѡ���������0~6֮��ѡ��\n");
            getchar();
            getchar();
        }
    }
    return m;
}

int CreateSubMenu2(char *user)      //�Ӳ˵� �����뻹��
{
    int m = 0;
    while(1)
    {
        system("cls");
        printf("\n               \t\t\tͼ�����Ա��%s���밴��ʾѡ��\n\n", user);
        printf("������Ϣά��");
        printf("              �����뻹�� ");
        printf("              ��Ϣͳ�����ѯ");
        printf("              �˳�ϵͳ\n\n");
        printf("                            1-����\n");
        printf("                            2-����");
        printf("                            0-������һ���˵�");
        printf("��ѡ��0~2����");
        scanf("%d", &m);
        if( m >= 0 && m <= 2 )
            break;
        else
        {
            printf("\nѡ���������0~2֮��ѡ��\n");
            getchar();
            getchar();
        }
    }
    return m;
}

int CreateSubMenu3(char *user)//�Ӳ˵� ��Ϣͳ�����ѯ
{
    int m = 0;
    while(1)
    {
        system("cls");
        printf("\n                      \t\t\tͼ�����Ա��%s���밴��ʾѡ��\n\n", user);
        printf("������Ϣά��");
        printf("            �����뻹��");
        printf("            ��Ϣͳ�����ѯ");
        printf("            �˳�ϵͳ\n\n");
        printf("                            1-ͼ���嵥\n");
        printf("                            2-�����嵥\n");
        printf("                            3-ͼ���ѯ\n");
        printf("                            4-���߲�ѯ\n");
        printf("                            0-������һ���˵�\n");
        printf("��ѡ��0~4����");
        scanf("%d", &m);
        if( m >= 0 && m <= 4 )
            break;
        else
        {
            printf("\nѡ��������ڣ�0~4��֮��ѡ��\n");
            getchar();
            getchar();
        }
    }
    return m;
}
#endif // MENU_H_INCLUDED
