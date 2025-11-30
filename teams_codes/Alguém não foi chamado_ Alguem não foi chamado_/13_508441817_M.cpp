#include <algorithm>
#include<bits/stdc++.h>
#include <cstdint>
#include <unordered_map>

using namespace std;

unordered_map<uint64_t, uint64_t> m;

uint64_t calc(uint64_t tempo) {
    uint64_t out = 0;

    for(auto e : m) {
        out += (tempo / e.first) * e.second;
    }

    return out;
}

int main() {
    uint64_t N, T;

    cin >> N >> T;

    for(uint64_t i = 0; i < N; i++) {
        uint64_t x;
        cin >> x;

        m[x]++;
    }

    uint64_t low = 1, high = 1e18;
    uint64_t mid;

    while(low <= high) {
        mid = (high + low) / 2;
        uint64_t produtos = calc(mid);

        if(produtos >= T) {
            high = mid - 1;
        }
        else if(produtos < T) {
            low = mid + 1;
        }
    }

    cout << mid << '\n';

    return 0;
}