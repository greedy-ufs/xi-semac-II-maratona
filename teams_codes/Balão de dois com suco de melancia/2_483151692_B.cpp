#include <bits/stdc++.h>
using namespace std;

const long long MAX = 1e5 + 5;

vector<bool> vis(MAX, false);
vector<long long> dist(MAX, LLONG_MAX);
vector<vector<long long>> g(MAX);

void bfs(long long n)
{
    queue<long long> q;
    q.push(0);
    dist[0] = 0;

    while (!q.empty())
    {
        int v = q.front(); q.pop();
        vis[v] = true;

        for (long long i = 0; i < g[v].size(); i++)
        {
            long long w = g[v][i];

            if (!vis[w])
            { 
                q.push(w);
                dist[w] = min(dist[v] + 1, dist[w]);
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    long long V, E; cin >> V >> E;

    for (long long i = 0; i < E; i++) {
        long long v1, v2; cin >> v1 >> v2; v1--; v2--;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bfs(V - 1);

    if (dist[V - 1] == LLONG_MAX) cout << "MAUS CAMINHOS!" << endl;
    else cout << dist[V - 1] + 1 << endl;

    return 0;
}