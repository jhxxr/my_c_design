#include <stdio.h>
#include <stdlib.h>
struct font{
    char img[8][25];
    int width;
    char c;
};
int main(){
    FIRE *fp;
    int rows=0;
    int c ;
    int i,j;
struct font fonts[102];
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
        for (i=0;i<102;i++){
            for(j=0;j<8;j++){
                fgets(fonts[i].img[j],30,fp);
            }
        }
    }
    fclose(fp);
    for (i=0;i<8;i++){
        printf("%s\n",fonts[10]img[i]);
    }
}