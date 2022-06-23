struct font
{
    char img[100][50]; //改大了。原：char img[8][25];
    int width;
    char c;
};
void loadfonts();
struct font getfont(char c);