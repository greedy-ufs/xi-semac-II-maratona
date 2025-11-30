#include<bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;


#define INF 100000000



int main() {


    int n, m; cin >> n >> m;



    vector<vector<int>> adj (n+1);


    for (int c = 0; c < m; c++){
        int o, d; cin >> o >> d;

        adj[o].push_back(d);
        adj[d].push_back(o);

    }

    queue<int> pq;

    pq.push(1);

    vector<int> visited (n+1, 0);
    vector<int> dist (n+1, INF);
    dist[1] = 0;



    while (!pq.empty()) {
        int nxt = pq.front();
        pq.pop();
        visited[nxt] = 1;

        if (nxt == n) break;


        for (int f : adj[nxt]){
            if (visited[f]) continue;
            dist[f] = min(dist[nxt] + 1, dist[f]);
            pq.push(f);
        }
    }

    
    if (dist[n] == INF) cout << "MAUS CAMINHOS!" << endl;
    else cout << dist[n] + 1 << endl;


    return 0;
}