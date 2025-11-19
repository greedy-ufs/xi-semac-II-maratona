#include <bits/stdc++.h>
using namespace std; 

#define endl '\n' 

typedef long long ll;
 
const int MAXN = 2e5 + 10;
ll n, t, k[MAXN];
 
bool possible(ll m) {
    ll prod = 0;
    for (int i = 0; i < n; i++) {
        prod += (m / k[i]);
        if (prod >= t) return true;
    }
    return false;
}
 
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> k[i];
    sort(k, k+n);
    ll l = 0, r = 1e18;
    while (l < r) {
        ll m = l + (r-l)/2;
        if (possible(m)) r = m;
        else l = m + 1;
    }
    cout << l << endl;
}
