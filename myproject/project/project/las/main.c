#include <stdio.h>
#include <string.h>
#include "display.h"
#include "parse.h"
#include "loadfonts.h"
#include "fileflf.h"



int main(int argc,char *argv[]){

	int flfh = 0;
    int flfs = 0;
	char files[50]={0};
	char messages[]={0};
	char fliename[]={0};
    int width;
    char align;
    char message[100];
	parse(argc,argv,&align,&width,message,fliename);
	strcpy(files,fliename);
	strcpy(messages,message);

    skipline(fliename,&flfs,&flfh);
    loadfonts(flfh,flfs,files,align,width,message);


}