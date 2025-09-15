#include <stdio.h>
#include <string.h>

char distancia(int letra);
char prox(int letra);

char alfabeto[24];
int main(int argc, char const *argv[])
{
    char word[30], cifra[90]={0};
    int i, j=0, letra=0, k, len;

    for (i = 0; i < 26; i++)
    {
        if (97 + i == 119 || 97 + i == 121)
        {
            continue;
        }
        else
        {
            if(97+i==97 || 97+i==101 || 97+i==105 || 97+i==111 || 97+i==117)
            {
                alfabeto[j] = 65 + i;
                j++;
            }else 
            {
                alfabeto[j] = 97 + i;
                j++;
            }
        }
    }
    j=0;
    fgets(word, 30, stdin);
    len=strlen(word);
    if (word[len-1]=='\n'){
        word[len-1]='\0';
        len--;
    }

    for (i = 0; i < len; i++)
    {
        for (k=0; k<24; k++){
            if (word[i]==alfabeto[k] || word[i]==alfabeto[k]+32)
            {
                break;
            }
        }
        letra=k;
        if (alfabeto[letra]<90)
        {
            cifra[j]=alfabeto[letra]+32;
            j++;
        } else {
            cifra[j]=alfabeto[letra];
            j++;
            cifra[j]=distancia(letra);
            j++;
            cifra[j]=prox(letra);
            j++;
        }
        letra=0;
    }
    
    len=strlen(cifra);

    printf("%s\n", cifra);

    return 0;
}

char prox(int letra){
    int i;
    if (letra==23)
    {
        return alfabeto[letra];
    }
    for (i = 1; i < 23; i++)
    {
        if (alfabeto[letra+i]>90)
        {
            return alfabeto[letra+i];
        } 
        else {
            continue;
        }
        
    }
    return alfabeto[letra];
}

char distancia(int letra){
    int i, distancia[2]={0};
    for (i = 0; i < 24; i++)
    {
        if (alfabeto[letra+i]<90 || alfabeto[letra+i]==122)
        {
            if (alfabeto[letra+i]==122)
            {
                distancia[0]=-1;
            }
            break;
        }
        else
        {
            distancia[0]++;
        }
    }
    for (i = 0; i < 24; i++)
    {
        if (letra - i < 0) break;
        if (alfabeto[letra-i]<90)
        {
            break;
        }
        else
        {
            distancia[1]++;
        }
    }
    if (distancia[0]>-1&& distancia[0]<distancia[1])
    {
        return alfabeto[letra+distancia[0]]+32;
    } else if (distancia[0]>distancia[1])
    {
        return alfabeto[letra-distancia[1]]+32;
    } else {
        return alfabeto[letra-distancia[1]]+32;
    }
}