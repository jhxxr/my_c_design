#include <stdio.h>
#include <stdlib.h>


int main (int argc,char *argv[]){
    int i;
	char align= '1';
	int width = 10;
    for (i = 0;i<argc;i++){
        if (argv[i][0]=='-'){
            switch(argv[i][0]){
                case 'l':
                case 'r':
                case 'c':
                   align = argv[i][0];
                   break;
                case 'w':
                   width = atoi(argv[i+1]);
                   break;
            }
        }  
    }
    printf ("slign=%c,width = %d",align,width);
}