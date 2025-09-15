#include <stdio.h>
#include <string.h>

int main()
{
    char reg[1000][20] = {0}, pref[1000][20] = {0}, acao[15], nome[20];
    int idade, ppref = 0, preg=0, i = 0, j = 0;

    do
    {
        for (i = 0; i < 3; i++)
        {
            scanf("%s", acao);
            if (strcmp(acao, "ATENDIMENTO") == 0)
            {
                fflush(stdin);
                break;
            }
            else
            {
                scanf("%s %d", nome, &idade);
                break;
            }
        }
        fflush(stdin);

        if (strcmp(acao, "CHEGADA") == 0)
        {
            if (idade > 54)
            {
                for (i = 0; i > -1; i++)
                {
                    if (pref[i][0] != '\0')
                    {
                        continue;
                    }
                    else
                    {
                        strcpy(pref[i], nome);
                        break;
                    }
                }
                ppref++;
            }
            else
            {
                for (i = 0; i < 999; i++)
                {
                    if (reg[i][0] != '\0')
                    {
                        continue;
                    }
                    else
                    {
                        strcpy(reg[i], nome);
                        break;
                    }
                }
                preg++;
            }
        } //FUNCIONA

        if (strcmp(acao, "ATENDIMENTO") == 0)
        {

            if (pref[0][0] != '\0')
            {
                printf("%s\n", pref[0]);
                for (i = 0; i < ppref-1; i++)
                {
                    if (pref[i + 1][0] != '\0')
                    {
                        strcpy(pref[i], pref[i + 1]);
                        pref[i + 1][0] = '\0';
                    }
                    else if (pref[i+1][0] == '\0' && pref[i][0]!='\0')
                    {
                        break;
                    }
                }
                ppref--;
                if (ppref==0) pref[0][0]='\0';
                
            }
            else
            {
                printf("%s\n", reg[0]);
                for (i = 0; i < preg-1; i++)
                {
                    if (reg[i + 1][0] != '\0')
                    {
                        strcpy(reg[i], reg[i + 1]);
                        reg[i + 1][0] = '\0';
                    }
                    else if (reg[i+1][0] == '\0' && reg[i][0]!='\0')
                    {
                        break;
                    }
                }
                preg--;
                if (preg==0) reg[0][0]='\0';
            }
        }
    } while (ppref>0 || preg>0);

    return 0;
}