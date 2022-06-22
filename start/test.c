#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//读取跳过文件行数
int skipline(char *fliename,int *flfskip,int *flfheight){
    FILE * fp;
    int rowx=0;
    int i,j,k;
    char ttfsj[50]={0};
    char flienames[50];
    for(i=0;i<50;i++){
        flienames[i]=fliename[i];
    }
    fp=fopen(flienames,"r");
    if(fp==NULL){
        exit(0);
    }
    while (1)
    {
        fscanf(fp,"%s",ttfsj);
        rowx++;
        if (rowx==2) {
            *flfheight=atoi(ttfsj);
        }
        if (rowx==6){
            *flfskip=atoi(ttfsj)+1;
            break;
        }
    }
    fclose(fp);
}



int main(){
    int flfh = 0;
    int flfs = 0;
    int *flfheight = &flfh;
    int *flfskip = &flfs;
    char fliename[]="3-d.flf";
    skipline(fliename,flfskip,flfheight);
    printf("%d\n%d",flfh,flfs);

}