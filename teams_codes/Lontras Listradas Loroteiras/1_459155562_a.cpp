#include <bits/stdc++.h>
using namespace std;

int main () {

    int k;

    cin >> k;

    int fib[k];

    int n = ((1e9 )+ 7);


    fib [0] = 1;
    fib [1] = 1;

    for (int i = 2; i < k ; i++) {

        fib[i] = (fib[i - 1] + fib[i - 2])% n;
    }

    cout << fib[k-1] << endl;

    return 0;
}
