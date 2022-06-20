#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc,char *argv[]){
    int i;
	char align= '1';
	int width = 10;
    int start = 1;
    char message[100]={0};
    for (i = 0;i<argc;i++){
        if (argv[i][0]=='-'){
            switch(argv[i][0]){
                case 'l':
                case 'r':
                case 'c':
                   align = argv[i][0];
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
        strcat(message,' ');
    }
    strcat(message,argv[i]);
    printf ("slign=%c,width=%d,message=%c",align,width,message);
}