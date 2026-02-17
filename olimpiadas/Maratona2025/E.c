#include <stdio.h>

int pista[500][500]={0}, n, m;

int curva (int l, int c);

int main(int argc, char const *argv[])
{
    int i, j, a, b, cont=0;
    scanf("%d %d", &n, &m);
    if (n<3 || n>500 || m<3 || m>500) return 1;

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            scanf("%d", &pista[i][j]);
            if (pista[i][j]>2 || pista[i][j]<0) return 1;
        } 
    }
    
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if(pista[i][j]==1){
                if(curva(i, j)==1){
                    cont++;
                }
            }
        } 
    }

    printf("%d\n", cont);

    return 0;
}

int curva(int l, int c){
    if (l + 1 < n && c + 1 < m && l - 1 >= 0 && c - 1 >= 0) {
        if (pista[l+1][c] == 1 && pista[l][c+1] == 1 && pista[l-1][c-1] == 2) return 1;
    }
    if (l - 1 >= 0 && c + 1 < m && l + 1 < n && c - 1 >= 0) {
        if (pista[l-1][c] == 1 && pista[l][c+1] == 1 && pista[l+1][c-1] == 2) return 1;
    }
    if (l - 1 >= 0 && c - 1 >= 0 && l + 1 < n && c + 1 < m) {
        if (pista[l-1][c] == 1 && pista[l][c-1] == 1 && pista[l+1][c+1] == 2) return 1;
    }
    if (l + 1 < n && c - 1 >= 0 && l - 1 >= 0 && c + 1 < m) {
        if (pista[l+1][c] == 1 && pista[l][c-1] == 1 && pista[l-1][c+1] == 2) return 1;
    }
        
    return 0;
    }