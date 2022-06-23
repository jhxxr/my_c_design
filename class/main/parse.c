#include <stdlib.h>
#include <string.h>
void parse(int argc, char *argv[], char *align, int *width, char message[])
{
    int i;
    int start = 1;
    message[0] = '\0';
    for (i = 0; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            switch (argv[i][1])
            {
            case 'l':
            case 'r':
            case 'c':
                *align = argv[i][1];
                if (i + 1 > start)
                    start = i + 1;
                break;
            case 'w':
                *width = atoi(argv[i + 1]);
                if (i + 2 > start)
                    start = i + 2;
                break;
            }
        }
    }
    for (i = start; i < argc - 1; i++)
    {
        strcat(message, argv[i]);
        strcat(message, " ");
    }

    strcat(message, argv[i]);
}