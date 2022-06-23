#include "loadfonts.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void skiplines(int n, FILE *fp);
void load(FILE *fp);
void clear();
struct font fonts[102];
void loadfonts()
{
    FILE *fp;
    fp = fopen("3-d.flf", "r");  //**改******改成字体名字*********
    if (fp == NULL)
    {
        exit(0);
    }
    skiplines(2, fp); //**改**********跳过的行数**************
    load(fp);
    clear();
    fclose(fp);
}

void skiplines(int n, FILE *fp)
{
    int i;
    for (i = 0; i < n; i++)
    {
        while (fgetc(fp) != '\n')
            ;
    }
}

void load(FILE *fp)
{
    int i, j;
    for (i = 0; i < 102; i++)
    {
        for (j = 0; j < 8; j++) //**改*****根据字体的高度修改**********
        {
            fgets(fonts[i].img[j], 100, fp);  //改了最大长度，因为读到30就停了，有的字体比30长，原：fgets(fonts[i].img[j], 100, fp);
        }
        fonts[i].c = i + 32;
    }
}

void clear()
{
    int i, j, k;
    for (i = 0; i < 102; i++)
    {
        for (j = 0; j < 8; j++)  //**改*****根据字体的高度修改**********
        {
            for (k = 0;; k++)
            {
                if (fonts[i].img[j][k] == '$')
                {
                    fonts[i].img[j][k] = ' ';
                }
                if (fonts[i].img[j][k] == '@')
                {
                    fonts[i].img[j][k] = '\0';
                    break;
                }
            }
        }
        fonts[i].width = strlen(fonts[i].img[0]);
    }
}

struct font getfont(char c)
{
    int i;
    for (i = 0; i < 102; i++)
    {
        if (fonts[i].c == c)
        {
            return fonts[i];
        }
    }
    return fonts[0];
}