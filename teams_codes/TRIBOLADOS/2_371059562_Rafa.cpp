#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fir first
#define sec second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;
const int inf = 0x6f6f6f6f;

int N, M, ans;
bool vis[MAXN];
vector<int> L[MAXN];

void BFS(int X);

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    for(int i=0;i<M;i++){
        int A, B; cin >> A >> B;

        L[A].pb(B);
        L[B].pb(A);
    }

    BFS(1);

    if (vis[N]) cout << ans << endl;
    else cout << "MAUS CAMINHOS!" << endl;
}

void BFS(int X){
    queue<pii> Q;
    Q.push({1, 1});
    vis[1] = true;

    while(!Q.empty()){
        pii F = Q.front();
        Q.pop();
        //cout << F.fir << " " << F.sec << endl;
        if (F.fir == N) ans = F.sec;

        for(int i=0;i<L[F.fir].size();i++){
            if (!vis[L[F.fir][i]]){
                Q.push({L[F.fir][i], F.sec+1});
                vis[L[F.fir][i]] = true;
            }
        }
    }
}