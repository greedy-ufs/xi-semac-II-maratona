#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k, s; cin >> n >> m >> k >> s;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        int qtd = 0;
        for (int i = 0; i < n; i++) {
            int bit_x = (x >> i) & 1;
            int bit_s = (s >> i) & 1;
            if (bit_x != bit_s) qtd++;
        }
        if (qtd <= k) ans++;
    }
    cout << ans << endl;
}