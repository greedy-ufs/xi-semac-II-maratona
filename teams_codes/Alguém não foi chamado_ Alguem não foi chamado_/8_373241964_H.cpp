#include<bits/stdc++.h>

using namespace std;

int countbits(int n) {
    int out = 0;

    while(n != 0) {
        if(n & 1) {
            out++;
        }

        n >>= 1;
    }

    return out;
}

int main() {
    int N, Q, T, M;
    int out = 0;

    cin >> N >> Q >> T >> M;
    while(Q--) {
        int x;
        cin >> x;

        if(countbits(x ^ M) <= T) {
            out++;
        }
    }

    cout << out << '\n';

    return 0;
}