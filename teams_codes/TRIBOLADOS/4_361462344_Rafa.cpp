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

int N, T, ans;
pii it[MAXN];

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    for(int i=0;i<N;i++) cin >> it[i].sec >> it[i].fir;

    sort(it, it+N);

    for(int i=0;i<N;i++){
        if (it[i].sec >= T){
            T = it[i].fir;
            ans++;
        }
    }
    
    cout << ans << endl;
}