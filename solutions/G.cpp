#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    long long soma = 0LL;
    for (int i = 0; i < n; i++) {
        long long x; cin >> x;
        soma += x;
    }
    if (soma % n == 0) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }
}