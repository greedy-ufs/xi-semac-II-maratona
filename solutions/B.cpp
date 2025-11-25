#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define int long long int

const int MAXN = 1e5 + 10;

int n, m;
vector<int> adj[MAXN], dist(MAXN, -1);
bool vis[MAXN];
 
void bfs(int s) {
    queue<int> q; 
    q.push(s); vis[s] = true; 
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto u : adj[v]) if (!vis[u]) {
            dist[u] = dist[v] + 1;
            q.push(u); vis[u] = true;
        }
    }
}
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; 
        u--; v--;
        adj[u].pb(v); 
        adj[v].pb(u);
    }
    bfs(0);
    if (!vis[n-1]) {
        cout << "MAUS CAMINHOS!" << endl;
    } else {
        cout << (dist[n-1] + 1) << endl;
    }
}