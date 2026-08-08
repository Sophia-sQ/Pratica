#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int l, c;
    char mapa[101][101];
    int o[2];
    bool prox = true;
    cin >> l >> c;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mapa[i][j];
            if (mapa[i][j] == 'o')
            {
                o[0] = i;
                o[1] = j;
            }
        }
    }
    int i = 0, j = 1;
    while (prox == true)
    {
        if (mapa[o[i] - 1][o[j]] == 'H' && (o[i]-1)>=0)
        {
            mapa[o[i] - 1][o[j]]='P';
            o[i]=o[i]-1; 
        }
        else if (mapa[o[i]][o[j] + 1] == 'H' && (o[j]+1)<c)
        {
            mapa[o[i]][o[j] + 1]='P';
            o[j]=o[j]+1;
        }
        else if (mapa[o[i] + 1][o[j]] == 'H' && (o[i]+1)<l)
        {
            mapa[o[i] + 1][o[j]]='P';
            o[i]=o[i]+1;
        }
        else if (mapa[o[i]][o[j] - 1] == 'H' && (o[j]-1)>=0)
        {
            mapa[o[i]][o[j] - 1]='P';
            o[j]=o[j]-1;
        }
        else
        {
            prox = false;
            o[i]++; o[j]++;
        }
    }

    cout << o[i] << " " << o[j] << "\n";

    return 0;
}
