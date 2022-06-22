#include <stdio.h>
#include "display.h"
#include "parse.h"
#include "loadfonts.h"
#include "fileflf.h"



int main(int argc,char *argv[]){
	int flfh = 0;
    int flfs = 0;
    int *flfheight = &flfh;
    int *flfskip = &flfs;
	//
    char fliename[]="small.flf";
    int width;
    char align;
    char message[100];
    skipline(fliename,flfskip,flfheight);
    parse(argc,argv,&align,&width,message);
    loadfonts(flfh,flfs,fliename);
    display(align,width,message);

}