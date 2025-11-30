#include <bits/stdc++.h>
using namespace std;

int main(){

    int N; cin >> N;

    vector<int> ponto(N, 0);

    int soma = 0;

    for(int i=0; i<N; i++){
        cin >> ponto[i];
        soma += ponto[i];
    }
    
    if(soma%N == 0) cout << "SIM" << endl;
    else cout << "NAO" << endl;

    return 0;
}