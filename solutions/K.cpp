#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int n; cin >> n;
    while (n--) {
        string a; cin >> a;
        int i = 0, tam_s = (int) s.size();
        for (auto c : a) {
            if (i < tam_s && c == s[i]) {
                i++;
            }
        }
        if (i == tam_s) {
            cout << "MUITO FACIL" << endl;
        } else {
            cout << "NAO MUITO FACIL" << endl;
        }
    }
}