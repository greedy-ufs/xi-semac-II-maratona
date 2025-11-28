#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// O tabuleiro é 100x100, então usamos 105 para margem de segurança.
const int MAX_COORD = 105;
int G[MAX_COORD][MAX_COORD];

// Função para calcular o MEX (Minimum Excluded value)
// O MEX de um conjunto de números é o menor inteiro não-negativo
// que NÃO está presente no conjunto.
int calculate_mex(int l, int c) {
    set<int> reachable_states;

    // 1. Movimentos Verticais: Mover para qualquer linha k < l na mesma coluna c
    // O adversário pode mover a pedra para (k, c) onde 0 <= k < l
    for (int k = 0; k < l; k++) {
        reachable_states.insert(G[k][c]);
    }

    // 2. Movimentos Horizontais: Mover para qualquer coluna k < c na mesma linha l
    // O adversário pode mover a pedra para (l, k) onde 0 <= k < c
    for (int k = 0; k < c; k++) {
        reachable_states.insert(G[l][k]);
    }

    // 3. Movimentos Diagonais: Mover para (l-u, c-u)
    // O adversário pode mover a pedra diminuindo ambas as coordenadas em u >= 1
    for (int u = 1; (l - u) >= 0 && (c - u) >= 0; u++) {
        reachable_states.insert(G[l - u][c - u]);
    }

    // Encontrar o MEX
    int mex = 0;
    while (reachable_states.count(mex)) {
        mex++;
    }
    return mex;
}

// Pré-computa os números de Grundy para todo o tabuleiro
void precompute_grundy() {
    // Caso base: (0,0) é uma posição perdedora final, então G[0][0] = 0.
    // Como a matriz global é inicializada com 0, isso já está implícito,
    // mas deixamos explícito para clareza ou caso a inicialização mude.
    G[0][0] = 0; 
    
    // Preenchemos a tabela iterativamente.
    // A ordem dos loops garante que, ao calcular G[l][c],
    // todos os estados alcançáveis (que têm coordenadas menores) já foram calculados.
    for (int l = 0; l <= 100; l++) {
        for (int c = 0; c <= 100; c++) {
            if (l == 0 && c == 0) continue;
            G[l][c] = calculate_mex(l, c);
        }
    }
}

void solve() {
    int N;
    // Leitura segura do número de pedras
    if (!(cin >> N)) return;

    int total_xor = 0;
    for (int i = 0; i < N; i++) {
        int l, c;
        cin >> l >> c;
        // Acumula o XOR sum dos valores de Grundy das pedras.
        // Se houver múltiplas pedras, o jogo equivale à soma Nim dos jogos individuais.
        total_xor ^= G[l][c];
    }

    // Teorema de Sprague-Grundy:
    // Se o XOR sum > 0, o estado é vencedor para o jogador atual (Breno).
    // Se o XOR sum == 0, o estado é perdedor (Breno perde, Adversário vence).
    if (total_xor > 0) {
        cout << "Breno" << endl;
    } else {
        cout << "Adversario" << endl;
    }
}

int main() {
    // Otimização de I/O para competição
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_grundy();
    solve();

    return 0;
}