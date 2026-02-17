#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N=0, P[10]={0}, V=0, i, j, aux, m=0, cont=0;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &P[i]);
    }
    
    for (i = 0; i < N; i++){
        for (j = i+1; j < N; j++){
            if(P[i]<P[j]){
                aux=P[i];
                P[i]=P[j];
                P[j]=aux;
            }
        }
    }

    scanf("%d", &V);

    for (i = 0; i < 9; i++){
        for (j = i+1; j < 10; j++){
            if(m>V){
                continue;
            } else {
                m=m+j;
            }
        }
    }
    

    return 0;
}