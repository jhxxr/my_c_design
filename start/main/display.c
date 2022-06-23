#include "loadfonts.h"
#include <string.h>
#include <stdio.h>

void displayline(char *start, char *end, char align, int width, int hei);
char *split(char *start, int width);

void display(char align, int width, char message[], int hei)
{
    char *s = message; //让s指向message
    char *e;
    while (*s != '\0')
    {                                         //读取message这一行
        e = split(s, width);                  // e指向每行最后的一个字符
        displayline(s, e, align, width, hei); //打印行
        s = e + 1;                            // s指向下一行的第一个字符
    }
}

void displayline(char *start, char *end, char align, int width, int hei)
{

    char buffer[100][200] = {0}; //存放每个字符的图像
    int i, j;
    char *p;
    int sp = 0;
    for (i = 0; i < hei; i++)
    {
        for (p = start; p <= end; p++)
        {
            strcat(buffer[i], getfont(*p).img[i]); //从字体里找出对应的字符放入要打印的buffer中
        }
    }

    if (align == 'c')
    {                                         //如果是居中
        sp = (width - strlen(buffer[0])) / 2; //计算偏移量
    }
    else if (align == 'r')
    {                                   //如果是右对齐
        sp = width - strlen(buffer[0]); //计算偏移量
    }
    for (i = 0; i < hei; i++)
    {
        for (j = 0; j < sp; j++)
        {
            printf(" ");
        }
        printf("%s\n", buffer[i]);
    }
}
char *split(char *start, int width)
{                    //分割字符串，当字符串长度超过width时，返回最后前一个字符
    char *p = start; // p指向start
    int cur = 0;     //当前字符串的长度
    struct font f;   //定义一个font结构体
    while (*p != '\0')
    {
        f = getfont(*p); //从字体里找出对应的字符
        if (f.width + cur <= width)
        {                   //如果当前字符串的长度加上当前字符的宽度小于等于width
            cur += f.width; //当前字符串的长度加上当前字符的宽度
            p++;            // p指向下一个字符
        }
        else
        {
            break;
        }
    }
    return --p; //返回最后前一个字符
}
