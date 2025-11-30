#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

vector<bool> vis(MAX, false);
vector<int> dist(MAX, INT_MAX);
vector<vector<int>> g(MAX);

void bfs(int n)
{
    queue<int> q;
    q.push(0);
    dist[0] = 0;

    while (!q.empty())
    {
        int v = q.front(); q.pop();
        vis[v] = true;

        for (int i = 0; i < g[v].size(); i++)
        {
            int w = g[v][i];

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
    int V, E; cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int v1, v2; cin >> v1 >> v2; v1--; v2--;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bfs(V - 1);

    if (dist[V - 1] == INT_MAX) cout << "MAUS CAMINHOS!" << endl;
    else cout << dist[V - 1] + 1 << endl;

    return 0;
}