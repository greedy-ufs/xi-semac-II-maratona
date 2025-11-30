#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define dbg(v) cerr << #v << " = " << v << "\n"
#define fall(i, s, n) for(int i=s; i<n; i++)
#define rfall(i, s, n) for(int i=s; i>=n; i--)

const int MAXN = 1e5+7;

int dp[MAXN], dp2[MAXN]; // dp[i] = any seq at i, dp2[i] = not start with i

int a[MAXN];

vector<int> ad[MAXN];
bool p[MAXN];

void dfs(int v){
    p[v]=1, dp[v]=a[v];

    for(auto viz : ad[v]){
        if(!p[viz]){
            dfs(viz);

            dp2[v] += dp[viz];
            dp[v] = max(dp[v], dp2[viz]+a[v]);
        }
    }

    dp[v] = max(dp[v], dp2[v]);
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    fall(i, 1, n+1) cin >> a[i];

    fall(i, 0, n-1){
        int u, v; cin >> u >> v;

        ad[u].pb(v), ad[v].pb(u);
    }

    dfs(1);
    
    cout << dp[1] << "\n";
}