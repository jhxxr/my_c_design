struct font
{
    char img[100][50]; //�Ĵ��ˡ�ԭ��char img[8][25];
    int width;
    char c;
};
void loadfonts();
struct font getfont(char c);