#include <stdio.h>

int main()
{
    int n, m, i, j, p=0;
    char wall[500][500];

    scanf("%d %d", &n, &m);
    //if(n<3||n>500||m<3||m>500) return 1;
    fflush(stdin);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%c", &wall[i][j]);
            if(wall[i][j]!='o'&& wall[i][j]!='.' && wall[i][j]!='#') {printf("erro1"); return 1;}
            if(i>0 && wall[i][j]=='o') {printf("erro2"); return 1;}
            if ((i%2==0||j==0||j==m-1) && wall[i][j]=='#') {printf("erro3"); return 1;}
            
        }
        fflush(stdin);
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (wall[i][j]=='.')
            {
                if(wall[i-1][j]=='o') wall[i][j]='o';
                if(wall[i][j-1]=='o' && wall[i+1][j-1]=='#') wall[i][j]='o';
                if(wall[i][j+1]=='o' && wall[i+1][j+1]=='#') wall[i][j]='o';
                //if(wall[i][j]=='o' && wall[i+1][j]=='#') wall[i][j-1]='o';
                /*if (wall[i+1][j]=='#'){
                    for (int k = j; k < m; k++)
                    {
                        if (wall[i+1][j]=='#' && wall[i][j]=='.'){
                            p++;
                        } else {
                            break;
                        }
                    }
                    for (int k = j-1; k < p+j-1; k++)
                    {
                        wall[i][k]='o';
                    }
                }*/
                
            }
            
        }
        
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", wall[i]);
    }

    return 0;
}
