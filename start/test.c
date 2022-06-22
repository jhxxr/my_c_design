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
    int rowx=0;
    int i;
    char ttfsj[50]={0};
    fp=fopen("3-d.flf","r");
    if(fp==NULL){
        exit(0);
    }

    while (1)
    {
        fscanf(fp,"%s",ttfsj);
        rowx++;
        if (rowx==6)  break;
    }
    fclose(fp);

    

    printf("%s\n",ttfsj);






}