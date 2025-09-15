#include <stdio.h>

int main(int argc, char const *argv[])
{
    float A=0, B=0, C=0, maior=0;
    char ganhou;

    scanf("%f", &A);
    scanf("%f", &B);
    scanf("%f", &C);

    if (A>B){
        ganhou='A';
        maior=A;
    } else {
        ganhou='B';
        maior=B;
    }
    
    if(maior>C){
        printf("Equipe %c ganhou\n", ganhou);
    } else if (C>maior){
        ganhou='C';
        printf("Equipe %c ganhou\n", ganhou);
    } else {
        printf("Empatou\n");
    }

    return 0;
}
