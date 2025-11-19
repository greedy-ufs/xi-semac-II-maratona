#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n, a, t; cin >> n >> a >> t;
    int ans = 0;
    ans += (n / a) * t;
    n = n % a;
    if (n != 0) ans += t;
    cout << ans << endl;
}