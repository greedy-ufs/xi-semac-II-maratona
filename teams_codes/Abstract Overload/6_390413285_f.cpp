#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, A , T; cin >> N >> A >> T;

    int tempo;
    if(N<=A) tempo = T;
    else tempo = ((N/A)*T) + ((N%A)*T);
    
    cout << tempo << endl;

    return 0;
}