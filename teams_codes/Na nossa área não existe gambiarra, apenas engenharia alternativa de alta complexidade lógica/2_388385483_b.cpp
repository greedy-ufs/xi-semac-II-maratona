#include <bits/stdc++.h>
using namespace std;


#define rep(i,a,b) for(int i = int(a); i < int(b); i++)
const int MOD = 1e9 + 7;
#define pb push_back
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef long long ll;

#define all(x) (x).begin() (x).end() 

vector<vector<int>> G;
vi D;

int bfs(int n){
    int i = 0;
    queue<int> q;
    q.push(i);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto k : G[x]){
            if(D[k] == -1){
                D[k] = D[x] + 1;
                q.push(k);
            }
        }
    }
    return D[n-1];
}

int main(){

    int n, m; cin >> n >> m;

    G = vector<vector<int>>(n);
    D = vi(n,-1);
    D[0] = 0;

    rep(i,0,m){
        int a, b;
        cin >> a >> b;
        G[a-1].pb(b-1);
        G[b-1].pb(a-1);
    }

    int r = bfs(n);

    if(r == -1)
        cout << "MAUS CAMINHOS!";
    else 
        cout << r+1;

    cout << endl;


}