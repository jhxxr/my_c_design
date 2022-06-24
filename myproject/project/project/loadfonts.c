#include "loadfonts.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void skiplines(int n, FILE *fp);
void load(FILE *fp, int flfh);
void clear(int flfh);
struct font fonts[102];
void loadfonts(int flfh, int flfs, char *filename)
{
    FILE *fp;
    int i;
    char flienames[50];
    for (i = 0; i < 50; i++)
    {
        flienames[i] = filename[i];        
    }
    fp = fopen(flienames, "r");
    if (fp == NULL)
    {
        exit(0);
    }
    skiplines(flfs, fp);
    load(fp, flfh);
    clear(flfh);
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

void load(FILE *fp, int flfh)
{
    int i, j;
    for (i = 0; i < 102; i++)
    {
        for (j = 0; j < flfh; j++)
        {
            fgets(fonts[i].img[j], 100, fp);
        }
        fonts[i].c = i + 32;
    }
}

void clear(int flfh)
{
    int i, j, k;
    for (i = 0; i < 102; i++)
    {
        for (j = 0; j < flfh; j++)
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
                if (fonts[i].img[j][k] == '#')
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