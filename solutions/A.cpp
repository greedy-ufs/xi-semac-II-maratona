#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll long long
 
const ll MOD = 1e9 + 7;
 
ll fib(ll n) {
    if (n == 0 or n == 1) return n;
    ll a = 0; // fib(n-2)
    ll b = 1; // fib(n-1)
    ll c;
    
    for (int i = 2; i <= n; i++) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    
    return c;
}
 
signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
	
    cout << fib(n) << endl;
}
