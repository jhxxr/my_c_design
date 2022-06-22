struct font{
    char img[8][25];
    int width;
    char c;

};
void loadfonts();
struct font getfont(char c);