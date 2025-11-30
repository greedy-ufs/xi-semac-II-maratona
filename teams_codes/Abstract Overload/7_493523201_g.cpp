#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin >> n;
    int soma = 0;
    for(int i=0; i<n; i++){
            int r; cin >> r;
            soma += r;
        }



    if(n== 0) {
        cout << "SIM" <<endl;
    } else if(soma == n) {
        cout << "SIM" <<endl;
    } else if(soma % 2 == 0) {
        cout << "SIM" <<endl;
    } else {
        cout << "NAO" <<endl;
    }

/*
    int N; cin >> N;
    if(N==0) cout << "SIM" << endl;

    else{

        int soma = 0;
        int r;

        for(int i=0; i<N; i++){
            cin >> r;
            soma += r;
        }
    
        int rest = soma%N;

        if(rest == 0) cout << "SIM" << endl;
        else cout << "NAO" << endl;
    }
*/
    return 0;
}