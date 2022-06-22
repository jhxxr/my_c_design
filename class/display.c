#include "loadfonts.h"
#include <string.h>
#include <stdio.h>
void displayline(char *start,char *end ,char align ,int width){
    char buffer[8][200]={0};
    int i;
    char *p;
    for(i=0;i<8;i++){
        for (p=start;p<end;p++){
            strcat(buffer[i],getfont(*p).img[i])
        }
    }
    if (align=='c'){
        sp=(width-strlen(buffer[0]))/2;
    }else if (align =='r'){
        sp =width-strlen(buffer[0]);

    }
    for(i=0;i<8;i++){
        for(j=0;j<sp;j++){
            printf(" ")

        }
        printf("%s\n",buffer[i]);
    }
}

char *split(char *start,int width);
void display(char align,int width,char message[]){
    char *s=message;
    har *e;
    while(s!='\0'){
        e=split(s,width);
        displayline(s,e,align,width);
        s=e+1;

    }
}


char * split(char *start,int width){
    char *p=start;
    int cur =0;
    struct font f;
    while(*p='\0'){
        f= getfont(*p);
        if (f.width+cur=<width){
            cur +=f.width;
            p++;
        }else {
            break;

        }
    }
    return --p;
}

