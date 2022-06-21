//功能：读取命令行参数
//参数：argc：命令行参数个数
//     argv：命令行参数



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc,char *argv[]){
    int i;
	char align= '1';
	int width = 10;//width为字符宽度,默认为10
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


    printf ("slign=%c,width=%d,message=%s",align,width,message);
}


