#include<bits/stdc++.h>

using namespace std;

int fib(int n) {
    int a = 1;
    int b = 1;

    for(int i = 2; i < n; i++) {
        if(i % 2 == 0) {
            b += a;
            b %= 1'000'000'007;
        }
        else {
            a+= b;
            b %= 1'000'000'007;
        }
    }

    if(n % 2 == 0) {
        return a;
    }
    else {
        return b;
    }

}

int main() {
    int a;

    cin >> a;

    cout << fib(a) << '\n';

    return 0;
}