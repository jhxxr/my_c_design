#include <stdio.h>
#include "display.h"
#include "parse.h"
#include "loadfonts.h"



int main(int argc,char *argv[]){
    ///align,width,message
    int width;
    char align;
    char message[100];

    parse(argc,argv,&width,&align,message);
    loadfonts();
    display(align,width,message);

}