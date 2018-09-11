#ifndef CONVERT_H_INCLUDED
#define CONVERT_H_INCLUDED

#include "myhead.h"

//将浮点数类型的字符串转换为浮点数，本算法未考虑负数和小于1.0的数值的转换
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
        if(*pr >= '0' && *pr <= '9' && flag)//对于整数部分计算
            resultNum = resultNum * 10 + (*pr - '0');
        else                                    //对含有小鼠部分的运算
        {
            resultNum = resultNum * 10 + (*pr - '0');
            resultNum = resultNum / 10;
        }
        pr++;
    }
    return resultNum;
}

#endif // CONVERT_H_INCLUDED
