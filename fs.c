//**2022年6月20日
//**本文件为课堂示例代码
//**作用：读取字体文件
//**

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//创建一个结构体，用于存储命令行参数
struct font{
    char img[8][25];
    int width;
    char c;

};



int main(){
    FILE * fp;
    int rows=0;
    int c ;
    int i,j,k;
    struct font fonts[102];
    char buffer[8][100]={0};
    fp=fopen("3-d.flf","r");
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
            fonts[i].c=i+32;//转换为*的ACII码值，42
            fonts[i].width=strlen(fonts[i].img[0]);
        }
    
    fclose(fp);
    /*
    for (i=0;i<8;i++){
        printf("%s\n",fonts[10]img[i]);
    }
    printf("char=%c,width=%d\n",fonts[10].c,fonts[10].width);
    */
    for(i=0;i<8;i++){
        strcat(buffer[i],fonts[65].img[i]);//字母a的asii码值
        strcat(buffer[i],fonts[66].img[i]);//字母b的asii码值
    }
    for(i=0;i<8;i++){
        printf("%s\n",buffer[i]);
    }
}