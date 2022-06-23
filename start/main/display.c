#include "loadfonts.h"
#include <string.h>
#include <stdio.h>

void displayline(char *start, char *end, char align, int width, int hei);
char *split(char *start, int width);

void display(char align, int width, char message[], int hei)
{
    char *s = message; //��sָ��message
    char *e;
    while (*s != '\0')
    {                                         //��ȡmessage��һ��
        e = split(s, width);                  // eָ��ÿ������һ���ַ�
        displayline(s, e, align, width, hei); //��ӡ��
        s = e + 1;                            // sָ����һ�еĵ�һ���ַ�
    }
}

void displayline(char *start, char *end, char align, int width, int hei)
{

    char buffer[100][200] = {0}; //���ÿ���ַ���ͼ��
    int i, j;
    char *p;
    int sp = 0;
    for (i = 0; i < hei; i++)
    {
        for (p = start; p <= end; p++)
        {
            strcat(buffer[i], getfont(*p).img[i]); //���������ҳ���Ӧ���ַ�����Ҫ��ӡ��buffer��
        }
    }

    if (align == 'c')
    {                                         //����Ǿ���
        sp = (width - strlen(buffer[0])) / 2; //����ƫ����
    }
    else if (align == 'r')
    {                                   //������Ҷ���
        sp = width - strlen(buffer[0]); //����ƫ����
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
{                    //�ָ��ַ��������ַ������ȳ���widthʱ���������ǰһ���ַ�
    char *p = start; // pָ��start
    int cur = 0;     //��ǰ�ַ����ĳ���
    struct font f;   //����һ��font�ṹ��
    while (*p != '\0')
    {
        f = getfont(*p); //���������ҳ���Ӧ���ַ�
        if (f.width + cur <= width)
        {                   //�����ǰ�ַ����ĳ��ȼ��ϵ�ǰ�ַ��Ŀ��С�ڵ���width
            cur += f.width; //��ǰ�ַ����ĳ��ȼ��ϵ�ǰ�ַ��Ŀ��
            p++;            // pָ����һ���ַ�
        }
        else
        {
            break;
        }
    }
    return --p; //�������ǰһ���ַ�
}
