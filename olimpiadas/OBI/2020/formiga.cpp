
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int s, t, p;
    cin >> s >> t >> p;
    vector <int> altura;
    vector <vector <int>> tunel;
    altura.resize(s+1, 0);
    tunel.resize(s+1);

    vector <int> fila={p};
    vector <int> visitados;
    int d=0;

    int i=0;

    for (i=1; i<=s; i++){
        cin >> altura[i];
    }

    for (i=1; i<=t; i++){
        int a, b;
        cin >> a >> b;
        if (altura[a]>altura[b]){
            printf("add %d no %d\n", b, a);
            tunel[a].push_back(b);
        }
        else {
            printf("add %d no %d\n", a, b);
            tunel[b].push_back(a);
        }

    }

    /*for (i=1; i<tunel.size(); i++){
        for (int j = 0; j < tunel[i].size(); j++)
        {
            cout << tunel[i][j]<<" ";
        }
        cout << endl;
    }*/

    i=0;
    //fix
    while(fila[i]){
        visitados.push_back(fila[i]);
        if (tunel[i]!=0){
            fila.push_back(tunel[fila[i]]);
        }
        
        i++;
        d++;
    }

    //printf("%d\n", d);

    return 0;
}
