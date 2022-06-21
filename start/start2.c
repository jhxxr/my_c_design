//可换字体文件版
//字体文件保存在fonts文件夹中
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义结构体

struct font{
    char img[8][25];
    int width;
    char c;
};
//字体文件处理函数
int chuli(char *ttf);
//打印函数
int outprint(char *mes,char *ttf);



//***********************************************************************************************
//主函数 获取命令行参数
int main (int argc,char *argv[]){
    int i;
    char ttf[50]="3-D";
	char align= '1';
	int width = 10;
    int start = 1;
    char message[100]={0};
    for (i = 0;i<argc;i++){
        if (argv[i][0]=='-'){
            switch(argv[i][1]){
                case 'l':
                case 'r':
                case 'c':
                case 'f':
                   align = argv[i][1];
                   if(align=='f'){
                        strcpy(ttf,argv[i+1]);
                   }
                   if (i+1>start)
                       start = i+1;
                   break;
                case 'w':
                   width = atoi(argv[i+1]);
                   if (i+2>start)
                       start = i+2;
                   break;
            }
        }  
    }
    
    for (i=start ;i<argc-1;i++){
        strcat(message,argv[i]);
        strcat(message," ");
    }

    strcat(message,argv[i]);
    outprint(message,ttf);


}
//***********************************************************************************************





//***********************************************************************************************
//打印函数
int outprint(char *mes,char *ttf){
    FILE * fp;
    int rows=0,rowx=0;
    int c,mzt;
    char cc;
    char ttfsj[50]={0};
    int maxwidth=0;
    int i,j,k;
    struct font fonts[102];
    char buffer[8][100]={0};
    chuli(ttf);//处理ttf变量
    fp=fopen(ttf,"r");
    if(fp==NULL){
        exit(0);
    }

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
        for (i=0;i<102;i++){
            for(j=0;j<8;j++){
                fgets(fonts[i].img[j],30,fp);
                for(k=0;k<strlen(fonts[i].img[j]);k++){
                    if(strlen(fonts[i].img[j])>maxwidth)
                        maxwidth=strlen(fonts[i].img[j]);
                    if(fonts[i].img[j][k]=='$'){
                        fonts[i].img[j][k]=' ';
                    }
                    if(fonts[i].img[j][k]=='@'){
                        fonts[i].img[j][k]='\0';
                        break;
                    }
                }
            }
        }  
    fclose(fp);
    for(i=0;i<8;i++){
        for(j=0;j<100;j++){
            mzt = mes[j]-32;//在字体中的位置
            strcat(buffer[i],fonts[mzt].img[i]);
            }
    }
    for(i=0;i<8;i++){
        printf("%s\n",buffer[i]);
    }
}
//***********************************************************************************************






//***********************************************************************************************
//处理ttf变量
int chuli(char *ttf){
    //打印ttf变量
    int i;
    char tt[50]={0};
    char wei[4]=".flf";
    char tou[50]="fonts/";
    for(i=0;i<50;i++){
        tt[i]=ttf[i];
    }
    //将wei放入ttf变量
    for(i=0;i<4;i++){
        ttf[i+strlen(tt)]=wei[i];
    }
    strcpy(tt,ttf);
    //将ttf放入tou变量
    for(i=0;i<strlen(tt);i++){
        tou[i+6]=ttf[i];
    }
    //将tou放入ttf变量
    strcpy(ttf,tou);
}
//***********************************************************************************************