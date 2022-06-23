struct font{
    char img[8][25];
    int width;
    char c;

};
void loadfonts(int flfh,int flfs,char *filename,char align,int width,char message[]);
struct font getfont(char c);