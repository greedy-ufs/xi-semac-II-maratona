#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define dbg(v) cerr << #v << " = " << v << "\n"
#define fall(i, s, n) for(int i=s; i<n; i++)
#define rfall(i, s, n) for(int i=s; i>=n; i--)

const int MAXN = 1e5+7;

int v[MAXN][30];
int b[30];

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,x,t,a;
    cin >> n >> x >> t;

    cin >> a;
    for(int r = 0;r <= n;r++) b[r] = a&(1<<r);
    
    int res = 0;
    for(int r = 0;r <= x;r++){
        cin >> a;
        int e = 0;
        for(int i = 0;i <= x;i++){
            if(a&(1<<r)){
                if(!b[i]) e++;
            }
            else{
                if(b[i]) e++;
            }
        }
        if(e<=t) res++;
    }
    cout << res << endl;
}