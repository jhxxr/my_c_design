struct font{
    char img[100][100];
    int width;
    char c;

};
void loadfonts(int flfh,int flfs,char *filename);
struct font getfont(char c);