#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    // conta nome senha saldo
    float saldo[100];
    char letra[40], titular[100], senha[100];
    int i = 0, n_conta[100], c, cont = 0;

    FILE *p = fopen("arquivo.txt", "r");

    /*//leitura da palavra
    scanf("%s", string);
    fprintf(p, "%s", string);
    fclose(p);*/

    while ((c = fgetc(p)) != EOF) // letra precisa ser um interio porque EOF é um inteiro
    {
        if (c == '-')
        {
            cont++;
            i=0;
        }
        else
        {
            if (cont == 0)
            {
                n_conta[i] = c - '0';
            }
            else if (cont == 1)
            {
                titular[i] = c;
            } else if (cont == 2)
            {
                senha[i] = c;
            }
            else if (cont == 3)
            {
                saldo[0] = atoi(p);
            }

            i++;
        }
    }

    fclose(p);
    printf("%d%d%d%d\n", n_conta[0],  n_conta[1], n_conta[2], n_conta[3]);
    printf("%s\n", titular);
    printf("%s\n", senha);
    printf("%.2f\n", saldo[0]);
    return 0;
}
