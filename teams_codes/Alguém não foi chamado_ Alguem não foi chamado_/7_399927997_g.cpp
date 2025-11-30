#include<bits/stdc++.h>
#include <cstdint>

using namespace std;

int main() {
    int n; cin >> n;
    int slaporra = n;

    uint64_t out = 0;

    while(n--) {
        int x;
        cin >> x;

        out += x;
    }

    if(out % slaporra == 0) {
        cout << "SIM\n";
    }
    else {
        cout << "NAO\n";
    }

    return 0;
}