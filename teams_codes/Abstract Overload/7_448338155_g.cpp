#include <bits/stdc++.h>
using namespace std;

int main(){

    int N; cin >> N;
    if(N==0) cout << "SIM" << endl;

    else{
        vector<int> ponto(N);

        int soma = 0;

        for(int i=0; i<N; i++){
            cin >> ponto[i];
            soma += ponto[i];
        }
    
        int rest = soma%N;

        if(rest == 0) cout << "SIM" << endl;
        else cout << "NAO" << endl;
    }

    return 0;
}