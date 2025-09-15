#include <stdio.h>

int direcao(int x1, int y1, int x2, int y2);

int main(int argc, char const *argv[])
{
    int tab[8][8]={0}, in[2], fin[2], i, j, flag=0, rota;

    while (1){

        scanf("%d %d %d %d", &in[0], &in[1], &fin[0], &fin[1]);
        if((in[0]<1 || in[0]>8) || (in[1]<1 || in[1]>8) || (fin[0]<1 || fin[0]>8)  || (fin[1]<1 || fin[1]>8)){return 1;}
        if(in[0]==0 && in[1]==0 && fin[0]==0  && fin[1]==0){break;}

        in[0]--; --in[1]; --fin[0]; --fin[1];
        tab[fin[0]][fin[1]]=3;
        i=in[0]; j=in[1];

        if(direcao(in[0], in[1], fin[0], fin[1])==0){
            while(i>=fin[0] && j>=fin[1]){
                i--; j--;
                if(tab[i][j]==3){flag=1;}
            }
        }

        if(direcao(in[0], in[1], fin[0], fin[1])==1){
            while(i>=fin[0] && j<=fin[1]){
                i--; j++;
                if(tab[i][j]==3){flag=1;}
            }
        }

        if(direcao(in[0], in[1], fin[0], fin[1])==2){
            while(i<=fin[0] && j<=fin[1]){
                i++; j++;
                if(tab[i][j]==3){flag=1;}
            }
        }
        if(direcao(in[0], in[1], fin[0], fin[1])==3){
            while(i<=fin[0] && j>=fin[1]){
                i++; j--;
                if(tab[i][j]==3){flag=1;}
            }
        }
        
        flag==1?printf("possible\n"):printf("impossible\n");
        flag=0;
    }
    
    return 0;
}

int direcao(int x1, int y1, int x2, int y2){
    if(x1>x2 && y1>y2) {return 0;} //cima esquerda
    if(x1>x2 && y1<y2) {return 1;} //cima direita
    if(x1<x2 && y1<y2) {return 2;} //baixo direita
    if(x1<x2 && y1>y2) {return 3;} //baixo esquerda
}