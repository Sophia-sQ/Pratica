#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N, i, V[100000], f;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &V[i]);
    }
    f = N;
    for (i = 0; i < N; i++)
    {
        //printf("Num atual: %d\n", V[i]);
        for (int j = i + 1; j < N; j++)
        {
            //printf("Num que foi comaparado: %d\n", V[j]);
            if (V[i] == V[j])
            {
                f--;
            }
        }
    }
    if (f < 0) f = 0;
    printf("%d\n", f);
    return 0;
}
