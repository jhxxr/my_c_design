#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int chuli(char *ttf){
    //打印ttf变量
    int i;
    char tt[50]={0};
    char wei[4]=".flf";
    for(i=0;i<50;i++){
        if(ttf[i]=='\0'){
            break;
        }
        tt[i]=ttf[i];
    }
    printf("%s\n",tt);
    strcat(tt,wei);
    printf("%s\n",tt);
}



int main(){
    int width = 10;
    char message[100]={0};
    //储存“3-d”到ttf变量中
    char ttf[50]={0};
    strcat(ttf,"3-d");
    chuli(ttf);


}