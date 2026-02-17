#include <stdio.h>
int main(int argc, char const *argv[])
{
    int N, num[100000]={0}, i, soma=0, cont=0, j, val=0;

    scanf("%d", &N);
    //if (N<1 || N>100000) return 1;

    for (i = 0; cont < N; i++)
    {
        scanf("%d", &num[i]);
        //if (num[i]<0 || num[i]>100) return 1;
        
        if (num[i]==0){
            num[i-1]=0;
            i=i-2; 
            if (i<0)
            {
                i=0;
            }
            
        } else{
            val++;
        }
        cont++;
    }
    
    for (i = 0; i <= val; i++)
    {
        soma=soma+num[i];
    }
    printf("%d\n", soma);
    //if (soma<0 || soma>1000000) return 1;
    return 0;
}
