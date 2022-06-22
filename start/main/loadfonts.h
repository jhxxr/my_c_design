struct font{
    char img[8][25];
    int width;
    char c;

};
void loadfonts(int flfh,int flfs,char *filename);
struct font getfont(char c);