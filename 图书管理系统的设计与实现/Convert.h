#ifndef CONVERT_H_INCLUDED
#define CONVERT_H_INCLUDED

#include "myhead.h"

//�����������͵��ַ���ת��Ϊ�����������㷨δ���Ǹ�����С��1.0����ֵ��ת��
float ConvertToFloat(char *strNum)
{
    float resultNum = 0;
    int flag = 1;
    char *pr;
    pr = strNum;
    while( *pr != '\0')
    {
        if(*pr == '.')
        {
            flag = 0;
            pr++;
        }
        if(*pr >= '0' && *pr <= '9' && flag)//�����������ּ���
            resultNum = resultNum * 10 + (*pr - '0');
        else                                    //�Ժ���С�󲿷ֵ�����
        {
            resultNum = resultNum * 10 + (*pr - '0');
            resultNum = resultNum / 10;
        }
        pr++;
    }
    return resultNum;
}

#endif // CONVERT_H_INCLUDED
