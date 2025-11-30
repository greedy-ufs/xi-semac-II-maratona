#include<bits/stdc++.h>
#include <cstdint>

using namespace std;

int fib(int n) {
    uint64_t a = 1;
    uint64_t b = 1;

    for(int i = 2; i < n; i++) {
        if(i % 2 == 0) {
            b += a;
            b %= 1'000'000'007;
        }
        else {
            a+= b;
            a %= 1'000'000'007;
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

    if(a == 0) {
        cout << "0\n";
        return 0;
    }

    cout << fib(a) << '\n';

    return 0;
}