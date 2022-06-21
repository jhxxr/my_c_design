//不可换字体文件版
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct font{
    char img[8][25];
    int width;
    char c;
};

//打印函数
int outprint(char *mes);


//主函数 获取命令行参数
int main (int argc,char *argv[]){
    int i;
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
                   align = argv[i][1];
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
    outprint(message);


}




int outprint(char *mes){
    FILE * fp;
    int rows=0;
    int c ,mzt;
    int i,j,k;
    struct font fonts[102];
    char buffer[8][100]={0};
    fp=fopen("fonts/3-d.flf","r");
    if(fp==NULL){
        exit(0);
    }
    while(1){
        c=fgetc(fp);
        if(c=='\n'){
            rows++;
            if(rows==2){
                break;
            }
        }
    }
        for (i=0;i<102;i++){
            for(j=0;j<8;j++){
                fgets(fonts[i].img[j],30,fp);
                for(k=0;k<strlen(fonts[i].img[j]);k++){
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




