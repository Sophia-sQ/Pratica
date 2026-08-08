#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, n, k, x, y, q;
    vector<vector<int>> cidades;
    vector<vector<int>> frutas;
    vector<int> pais;
    vector<int> comprar;
    vector<int> fila;
    vector<int> visitas = {0};
    cin >> n >> k;
    frutas.resize(n + 2);
    frutas[n + 1] = vector<int>(k, 0);
    pais.resize(n + 1);
    cidades.resize(n + 1);
    visitas.resize(n + 1);

    for (i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        cidades[x].push_back(y);
        cidades[y].push_back(x);
    }

    i = 1;
    while (i <= n)
    {
        cin >> x;
        frutas[i].push_back(x);
        if (frutas[i].size() >= k) i++;
    }

    cin >> q;
    int atual;
    for (i = 0; i < q; i++)
    {
        fila.clear();
        // pais.clear();
        fill(visitas.begin(), visitas.end(), 0);
        fill(frutas[n + 1].begin(), frutas[n + 1].end(), 0);
        cin >> x >> y;
        atual = x;
        fila.push_back(x);
        int j = 0, s = 1;
        while (j < s)
        {
            atual = fila[j];
            if (atual == y)
            {
                while (atual != x)
                {
                    for (int a = 0; a < k; a++)
                    {
                        if (frutas[atual][a])
                        {
                            frutas[n + 1][a]++;
                        }
                    }
                    atual = pais[atual];
                }
                for (int a = 0; a < k; a++)
                {
                    if (frutas[x][a])
                    {
                        frutas[n + 1][a]++;
                    }
                }
                int b = 0;
                for (int a = 0; a < k; a++)
                {
                    if (frutas[n + 1][a] % 2 != 0)
                    {
                        b++;
                    }
                }
                cout << b << "\n";
                break;
            }
            visitas[atual] = 1;
            for (int cidade : cidades[atual])
            {
                if (!visitas[cidade])
                {
                    fila.push_back(cidade);
                    pais[cidade] = atual;
                }
            }
            s = fila.size();
            j++;
        }
    }

    return 0;
}
