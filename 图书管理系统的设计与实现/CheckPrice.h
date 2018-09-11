#ifndef CHECKPRICE_H_INCLUDED
#define CHECKPRICE_H_INCLUDED

#include "myhead.h"

int CheckPrice(char *inputPrice)//�ж������ͼ��۸�ĸ�ʽ�Ƿ���ȷ
{
    int IsRight = 1;
    char *pr;
    int dotCount = 0;
    pr = inputPrice;
    while(*pr != '\0')
    {
        if(!(*pr >= '0' && *pr <= '9') && *pr != '.')
            IsRight = 0;
        else if( *pr == '.' )
            dotCount++;
        pr++;
    }
    if(dotCount > 1)
        IsRight = 0;
    return IsRight;
}

#endif // CHECKPRICE_H_INCLUDED
