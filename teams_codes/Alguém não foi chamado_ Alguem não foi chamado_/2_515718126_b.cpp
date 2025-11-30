#include<bits/stdc++.h>
#include <cstdint>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;


#define INF INT32_MAX

uint32_t visited[100000+1];
uint32_t dist[100000+1];

int main() {

    memset(dist, -1, 100000+1);

    uint32_t n, m;
    scanf("%u", &n);
    scanf("%u", &m);
    //cin >> n >> m;



    vector<vector<uint32_t>> adj (n+1);


    for (uint32_t c = 0; c < m; c++){
        uint32_t o, d;
        scanf("%u %u", &o, &d);

        adj[o].push_back(d);
        adj[d].push_back(o);

    }

    queue<uint32_t> pq;

    pq.push(1);
    dist[1] = 0;



    while (!pq.empty()) {
        uint32_t nxt = pq.front();
        pq.pop();
        visited[nxt] = 1;

        if (nxt == n) break;


        for (uint32_t f : adj[nxt]){
            if (visited[f]) continue;
            dist[f] = min(dist[nxt] + 1, dist[f]);
            pq.push(f);
            visited[nxt] = 1;
        }
    }

    
    if (dist[n] == UINT32_MAX) printf("MAUS CAMINHOS!\n");
    else printf("%u\n", dist[n] + 1);


    return 0;
}