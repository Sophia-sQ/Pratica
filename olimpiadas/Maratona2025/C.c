#include <stdio.h>

int power(int N){
    int i, min=2000000000;
    if(N==1) return 2;
    if(N==2) return 3;
    for (i = 1; i < N; i++)
    {
        if(min>i*(N-1)) min=i*(N-1);
    }
    return min;
}

int main(int argc, char const *argv[])
{
    int prof=0;

    scanf("%d", &prof);
    printf("%d", power(prof));
    

    return 0;
}
