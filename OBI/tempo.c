#include <stdio.h>
int main(int argc, char const *argv[])
{
    int N, X[101] = {0}, T, i, ind, flag[101]={0};
    char ev;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%c %d", &ev, &ind);
        if (ev=='R')
        {
            flag[ind]=1;
            X[ind]++;
        }
        
    }

    return 0;
}
