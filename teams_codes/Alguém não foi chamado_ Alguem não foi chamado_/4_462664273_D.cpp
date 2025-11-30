#include<bits/stdc++.h>
#include <cstring>
#include <vector>

using namespace std;

bool zeros[500001];
bool horario[500001];

struct Evento {
    int inicio;
    int fim;

    Evento() : inicio(0), fim(0) {}
    Evento(int inicio, int fim) : inicio(inicio), fim(fim) {}

    bool operator<(Evento& other) {
        return (fim - inicio) < (other.fim - other.inicio);
    }
};

int main() {
    int N, out = 0;
    cin >> N;
    vector<Evento> eventos;


    for(int i = 0; i < N; i++) {
        int inicio, fim;

        cin >> inicio >> fim;

        if(inicio == fim) {
            out++;
            continue;
        }

        eventos.emplace_back(inicio, fim - 1);
    }

    sort(eventos.begin(), eventos.end());

    for(Evento& e : eventos) {
        if(memcmp(&zeros[e.inicio], &horario[e.inicio], e.fim - e.inicio + 1) == 0) {
            memset(&horario[e.inicio], true, e.fim - e.inicio + 1);
            out++;
        }
    }

    cout << out << '\n';

    return 0;
}