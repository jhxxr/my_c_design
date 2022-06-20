#include <stdio.h>
int main(int argc ,char *atgv[]){
    int i;
    for (i= 0 ; i< argc ;i++)
    printf("argc[%d]:%s\n",i,argc[i]);
}