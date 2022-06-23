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
    {                                    //��sָ��message
        e = split(s, width);             //��ȡmessage��һ��
        displayline(s, e, align, width); //��ӡ��
        s = e + 1;                       // sָ����һ�еĵ�һ���ַ�
    }
}

void displayline(char *start, char *end, char align, int width)
{
    char buffer[50][200] = {0}; //���ÿ���ַ���ͼ��   //char buffer[8][200] = {0};ԭ��Ϊ8��Ϊ����������������޸���
    int i, j;
    char *p;
    int sp = 0;
    for (i = 0; i < 8; i++)  //**��*****��������ĸ߶��޸�**********
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
    for (i = 0; i < 8; i++)  //**��*****��������ĸ߶��޸�**********
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
