#include <stdio.h>

int main(int argc, char const *argv[])
{
    char tab[8][8], input = 'L';
    int i, j = -1, k;

    for (i = 0; i < 8; i++)
    {
        j = 0;
        while (j < 8)
        {
            scanf("%c", &input);
            if (input == '/') continue;
            if (input > 48 && input < 57)
            {
                for (k = 0; k < input - 48 && j<8; k++, j++)
                {
                    tab[i][j] = ' ';
                }
            }
            else
            {
                tab[i][j] = input;
                j++;
            }
        }
    }

    for (i = 0; i < 8; i++)
    {
        printf("|");
        for (j = 0; j < 8; j++)
        {
            printf("%c|", tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}
