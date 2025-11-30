#include <bits/stdc++.h>
using namespace std;

int main () {

    int n;
    cin >> n;
    int p[n], soma = 0;

    if(n == 0){
        cout << "NAO" << endl;
    }
    else{
        for(int i = 0; i < n; i++){
        cin >> p[i];
        soma += p[i];
        }

        if(soma % n == 0){
          cout << "SIM" << endl;
        }  
    else{
        cout << "NAO" << endl;
    }
    }

    return 0;
}