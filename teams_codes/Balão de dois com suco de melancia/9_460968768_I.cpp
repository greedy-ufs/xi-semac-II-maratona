#include <bits/stdc++.h>
using namespace std;

vector<int> cores(1e5 + 5);
vector<bool> vis(1e5 + 5);
vector<int> econ(1e5 + 5);

void bfs(vector<vector<int>> g)
{
    int cor = 0;
    queue<int> q; q.push(0); cores[0] = cor;
    cor = 1;

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
                cores[w] = (cores[v] + 1) % 2;
                vis[v] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> g(n);
    
    for (int i = 0; i < n; i++) cin >> econ[i];

    for (int i = 0; i < n - 1; i++)
    {
        int v, w; cin >> v >> w; v--; w--;
        g[v].push_back(w);
        g[w].push_back(v);
    }

    bfs(g);

    vector<int> ans = { 0 , 0 };

    for (int i = 0; i < n; i++)
    {
        int cor = cores[i];
        ans[cor] += econ[i];
    }

    cout << max(ans[0], ans[1]) << endl;

    return 0;
}