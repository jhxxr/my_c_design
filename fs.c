//**2022年6月20日
//**本文件为课堂示例代码
//**作用：读取字体文件
//**

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//创建一个结构体，方便储存数据
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
                // fgets  从指定的 fp 中读取一行，并把它存储在 fonts[i].img[j] 所指向的字符串内。当读取 29(n-1) 个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止。
                for(k=0;k<strlen(fonts[i].img[j]);k++){
                    if(fonts[i].img[j][k]=='$'){
                        fonts[i].img[j][k]=' ';
                    }
                    if(fonts[i].img[j][k]=='@'){
                        fonts[i].img[j][k]='\0';
                        break;
                        //删除末尾的$ @字符
                    }
                }
            }
            fonts[i].c=i+32;//因为在字体里面*是11个，i为10，所以转换为*的ACII码值：42
            fonts[i].width=strlen(fonts[i].img[0]);
        }
    
    fclose(fp);//文件读取完要 关闭文件
    /*
    for (i=0;i<8;i++){
        printf("%s\n",fonts[10]img[i]);
    }
    printf("char=%c,width=%d\n",fonts[10].c,fonts[10].width);
    */
    for(i=0;i<8;i++){
        strcat(buffer[i],fonts[65].img[i]);
        strcat(buffer[i],fonts[35].img[i]);
    }
    for(i=0;i<8;i++){
        printf("%s\n",buffer[i]);
    }
}