#include <bits/stdc++.h>
using namespace std;

vector<bool> vis(1e5 + 5, false);

void bfs(vector<vector<int>> g)
{
    int cidades = -1;
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
        int v = q.front(); q.pop();
        vis[v] = true;
        cidades++;

        for (int i = 0; i < g[v].size(); i++)
        {
            int w = g[v][i];

            if (w == g.size() - 1) {
                cout << cidades << endl;
                return;
            }

            if (!vis[w]) q.push(w);
        }
    }

    cout << "MAUS CAMINHOS!" << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    int V, E; cin >> V >> E;
    vector<vector<int>> g(V);

    for (int i = 0; i < E; i++) {
        int v1, v2; cin >> v1 >> v2; v1--; v2--;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bfs(g);

    return 0;
}