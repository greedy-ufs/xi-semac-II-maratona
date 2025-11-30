#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define dbg(v) cerr << #v << " = " << v << "\n"
#define fall(i, s, n) for(int i=s; i<n; i++)
#define rfall(i, s, n) for(int i=s; i>=n; i--)

const int MAXN = 1e5+7;

int dp[MAXN];

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;

    int p[n], f[n];

    fall(i, 0, n) cin >> p[i];
    fall(i, 0, n) cin >> f[i];

    fall(i, 0, n){
        rfall(j, x, p[i]) dp[j] = max(dp[j], dp[j-p[i]]+f[i]);
    }

    int mx=0;

    fall(i, 0, x+1) mx = max(mx, dp[i]);

    cout << mx << "\n";
}