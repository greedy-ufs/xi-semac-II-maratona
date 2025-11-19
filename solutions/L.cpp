#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long
 
const int MAXN = 1e3 + 1;
const int MAXW = 1e5 + 1;
 
int n, x, dp[MAXW], peso[MAXN], fav[MAXN];
 
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> x;
    
    for (int i = 1; i <= n; i++) {
        cin >> peso[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> fav[i];
    }
    
    for (int i = 1; i <= n; i++) {
        int peso_atual = peso[i];
        int fav_atual = fav[i];
        for (int j = x; j >= peso_atual; j--) {
            dp[j] = max(dp[j], dp[j - peso_atual] + fav_atual);
        }
    }
    
    cout << dp[x] << endl;
}