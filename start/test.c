#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct font{
    char img[8][25];
    int width;
    char c;
};
int main(){
    FILE * fp;
    int rows=0,rowx=0;
    int c ;
    char cc;
    int i,j,k;
    struct font fonts[102];
    char buffer[8][100]={0};
    char ttfsj[50]={0};
    fp=fopen("fonts/1row.flf","r");
    if(fp==NULL){
        exit(0);
    }
    //读取第一行存入ttfsj
    while (1)
    {
        fscanf(fp,"%s",ttfsj);
        rowx++;
        if (rowx==6)  break;
    }
    rewind(fp);
    while(1){
        c=fgetc(fp);
        if(c=='\n'){
            rows++;
            if(rows==atoi(ttfsj)+1){
                break;
            }
        }
    }
    

    printf("%s\n",ttfsj);
    //读取ttfsj中最后一串字符串





}