#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'

const int MAXN = 1e5 + 10;

int n, eco[MAXN], dp1[MAXN], dp0[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];


void dfs(int v) {
    vis[v] = true;
    dp1[v] = eco[v];    // se escolher v
    dp0[v] = 0;         // se não escolher v
    for (auto u : adj[v]) if (!vis[u]) {
        dfs(u);
        dp1[v] += dp0[u]; // escolhendo v -> não pode escolher u
        dp0[v] += max(dp0[u], dp1[u]); // não escolhendo v -> melhor escolha em u
    }
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> eco[i];
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    cout << max(dp0[0], dp1[0]) << endl;
}