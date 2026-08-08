#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    // Otimização de leitura e escrita para C++ (útil para competições)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> l(n);
    long long total_length = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        total_length += l[i];
    }

    // Se o comprimento total for ímpar, não há como haver diâmetros perfeitos
    if (total_length % 2 != 0) {
        cout << "N\n";
        return 0;
    }

    long long half_length = total_length / 2;

    // Vetor para guardar as posições (distâncias acumuladas) de cada árvore a partir da primeira
    vector<long long> positions(n);
    long long current_pos = 0;
    
    for (int i = 0; i < n; i++) {
        positions[i] = current_pos;
        current_pos += l[i];
    }

    int diameters_found = 0;

    // Percorremos as árvores na primeira metade do círculo
    for (int i = 0; i < n; i++) {
        if (positions[i] >= half_length) {
            break; // Já passamos da metade, não precisamos checar o resto para evitar contar em dobro
        }
        
        // O alvo é o ponto exatamente do outro lado do círculo
        long long target = positions[i] + half_length;

        // Fazemos uma busca binária no vetor ordenado de posições
        if (binary_search(positions.begin(), positions.end(), target)) {
            diameters_found++;
            
            // Se acharmos pelo menos 2 diâmetros, fechamos um retângulo
            if (diameters_found == 2) {
                cout << "S\n";
                return 0;
            }
        }
    }

    // Se o laço terminar e não encontrarmos 2 diâmetros
    cout << "N\n";
    return 0;
}