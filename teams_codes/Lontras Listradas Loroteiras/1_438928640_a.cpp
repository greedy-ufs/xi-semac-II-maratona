#include <bits/stdc++.h>
using namespace std;

int main () {

    int k;

    cin >> k;

    int fib[k];


    fib [0] = 1;
    fib [1] = 1;

    cout << fib[0] << endl << fib [1] << endl ;

    for (int i = 2; i < k ; i++) {

        fib[i] = fib [i - 2] + fib [i - 1];
    
    }

    if (k > 46) {
        
        cout << fib[k-1] % (10^9 + 7) << endl;

    } else {
        
        cout << fib[k-1] << endl;
    }

    return 0;
}
