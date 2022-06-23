#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int chuli(char *ttf){
    int i;
    char tt[50]={0};
    char wei[5]="\.flf";

    for(i=0;i<50;i++){
        tt[i]=ttf[i];
    }

    for(i=0;i<5;i++){
        ttf[i+strlen(tt)]=wei[i];
    }
    strcpy(tt,ttf);
	return 0;
}

void parse(int argc ,char *argv[],char *align,int *width,char message[],char fliename[]){
    int i;
	//char align= '1';
	//int width = 10;
    int start = 1;	
	char filenames[50]={0};
    //char message[100]={0};
    message[0]='\0';

    for (i = 0;i<argc;i++){
        if (argv[i][0]=='-'){
            switch(argv[i][1]){
                case 'l':
                case 'r':
                case 'c':
                   *align = argv[i][1];
                   if (i+1>start)
                       start = i+1;
                   break;
                case 'w':
                   *width = atoi(argv[i+1]);
                   if(i+2>start)
                       start = i+2;
                   break;
				case 'f':
				       strcpy(filenames,argv[i+1]);
                   if(i+2>start)
                       start = i+2;
            }
        }  
    }
    for (i=start ;i<argc-1;i++){
        strcat(message,argv[i]);
        strcat(message," ");
    }
	strcpy(fliename,filenames);
	chuli(fliename);

    strcat(message,argv[i]);

}


