#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9 + 7;

int main() {

    int k; cin >> k;
    
    vector<long long> fib(k+1);
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;

    for(int i=3; i<=k; i++){
        fib[i] = (fib[i-1] + fib[i-2]) % MAX;
    }

    cout << fib[k] << endl;

    return 0;
}