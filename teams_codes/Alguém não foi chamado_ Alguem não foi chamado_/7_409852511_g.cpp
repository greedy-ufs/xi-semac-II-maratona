#include<bits/stdc++.h>
#include <cstdint>

using namespace std;

int main() {
    uint64_t n; cin >> n;
    uint64_t slaporra = n;

    uint64_t out = 0;

    if(slaporra == 0) {
        cout << "SIM\n";

        return 0;
    }

    while(n--) {
        int x;
        cin >> x;

        out = ((x + out) % slaporra);
    }

    if(out == 0) {
        cout << "SIM\n";
    }
    else {
        cout << "NAO\n";
    }

    return 0;
}