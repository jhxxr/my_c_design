#include "loadfonts.h"
#include <string.h>
#include <stdio.h>

void displayline(char *start, char *end, char align, int width);
char *split(char *start, int width);

void display(char align, int width, char message[])
{
    char *s = message;
    char *e;
    while (*s != '\0')
    {                                    //让s指向message
        e = split(s, width);             //读取message这一行
        displayline(s, e, align, width); //打印行
        s = e + 1;                       // s指向下一行的第一个字符
    }
}

void displayline(char *start, char *end, char align, int width)
{
    char buffer[50][200] = {0}; //存放每个字符的图像   //char buffer[8][200] = {0};原本为8，为了适配更多字体我修改了
    int i, j;
    char *p;
    int sp = 0;
    for (i = 0; i < 8; i++)  //**改*****根据字体的高度修改**********
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
    for (i = 0; i < 8; i++)  //**改*****根据字体的高度修改**********
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
