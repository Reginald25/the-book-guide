#ifndef COUNT_H_INCLUDED
#define COUNT_H_INCLUDED

#include "myhead.h"

int CountBook()//统计馆藏可借图书数量
{
    struct BookInfo bookItem;
    FILE *fp;
    int count = 0;
    if((fp = fopen("bookinfo.dat", "rb" )) == NULL )
        return 0;
    else
    {
        while(fread(&bookItem, BOOKLEN, 1, fp))
            if(bookItem.isAvailable == '1')
                count++
        fclose(fp);
        return count;
    }
}

int CountReader()   //统计合法读者总数
{
    struct ReaderInfo reader;
    FILE *fp;
    int count = 0;
    if((fp = fopen("readerinfo.dat", "rb")) == NULL)
        return 0;
    else
    {
        while(fread(&reader, READERLEN, 1, fp))
            if(reader.isAvailable == '1')
                count++;
        fclose(fp);
        return count;
    }
}


#endif // COUNT_H_INCLUDED
