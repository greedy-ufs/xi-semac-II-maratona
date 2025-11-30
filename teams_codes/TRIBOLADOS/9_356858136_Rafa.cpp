#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define dbg(v) cerr << #v << " = " << v << "\n"
#define fall(i, s, n) for(int i=s; i<n; i++)
#define rfall(i, s, n) for(int i=s; i>=n; i--)

const int MAXN = 1e5+7;

vector<int> ad[MAXN];
bool p[MAXN];

int a[MAXN], sum[2];

void dfs(int v, bool t){
    sum[t] += a[v], p[v]=1;

    for(auto viz : ad[v]) if(!p[viz]) dfs(viz, !t);
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    fall(i, 1, n+1) cin >> a[i];

    fall(i, 0, n-1){
        int u, v; cin >> u >> v;

        ad[u].pb(v), ad[v].pb(u);
    }

    dfs(1, 0);

    cout << max(sum[0], sum[1]) << "\n";
}