#include<bits/stdc++.h>
#include <cstdint>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;


#define INF INT64_MAX



int main() {


    long long int n, m;
    scanf("%lld", &n);
    scanf("%lld", &m);
    //cin >> n >> m;



    vector<vector<long long int>> adj (n+1);


    for (long long int c = 0; c < m; c++){
        long long int o, d;
        scanf("%lld %lld", &o, &d);

        adj[o].push_back(d);
        adj[d].push_back(o);

    }

    queue<long long int> pq;

    pq.push(1);

    vector<long long int> visited (n+1, 0);
    vector<long long int> dist (n+1, INF);
    dist[1] = 0;



    while (!pq.empty()) {
        long long int nxt = pq.front();
        pq.pop();
        visited[nxt] = 1;

        if (nxt == n) break;


        for (long long int f : adj[nxt]){
            if (visited[f]) continue;
            dist[f] = min(dist[nxt] + 1, dist[f]);
            pq.push(f);
            visited[nxt] = 1;
        }
    }

    
    if (dist[n] == INF) printf("MAUS CAMINHOS!\n");
    else printf("%lld\n", dist[n] + 1);


    return 0;
}