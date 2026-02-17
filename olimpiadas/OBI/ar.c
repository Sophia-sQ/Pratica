#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, m, i, j;
    char wall[500][500];

    scanf("%d %d", &n, &m);
    //if(n<3||n>500||m<3||m>500) return 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("&c", wall[i][j]);
            if(wall[i][j]!='o'||wall[i][j]!='.'||wall[i][j]!='#') return 1;
            if(i>0 && wall[i][j]=='o') return 1;
            if ((i%2!=0||j==0||j==m-1) && wall[i][j]=='#') return 1;
            
        }
        
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (wall[i][j]=='.')
            {
                if(i>0 && wall[i-1][j]=='o') wall[i][j]='o';
                if(i>0 && wall[i][j-1]=='o'&& wall[i+1][j-1]=='#') wall[i][j]='o';
                if(i>0 && wall[i][j+1]=='o' && wall[i+1][j+1]=='#') wall[i][j]='o';

            }
            
        }
        
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%c", wall[i][j]);
            
        }
        printf("\n");
    }

    return 0;
}
