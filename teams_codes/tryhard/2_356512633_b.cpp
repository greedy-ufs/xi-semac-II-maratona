#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    vector<int> dist(n+1,-1);
    dist[1]=1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto nbr : adj[u]){
            if(dist[nbr]==-1){
                q.push(nbr);
                dist[nbr] = dist[u] + 1;
            }
        }
    }

    if(dist[n] == -1){
        cout << "MAUS CAMINHOS" << '\n';
    }else cout << dist[n] << '\n';

    return 0;
}