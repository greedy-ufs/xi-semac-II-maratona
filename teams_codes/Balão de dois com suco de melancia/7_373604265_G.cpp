#include <bits/stdc++.h>
using namespace std;

void solve(int pontos, vector<int> porcoes)
{
    int soma = 0;
    for (const auto p : porcoes) soma += p;

    if (soma % pontos == 0) cout << "SIM" << endl;
    else cout << "NAO" << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    int pontos; cin >> pontos;

    vector<int> porcoes(pontos);
    for (int i = 0; i < pontos; i++) cin >> porcoes[i];

    solve(pontos, porcoes);

    return 0;
}