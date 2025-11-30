#include <bits/stdc++.h>
using namespace std;

#define dbgvec(v) for(auto x : v){cout << x << " ";} cout << endl;
#define rep(i,a,b) for(int i = int(a); i < int(b); i++)
#define per(i,a,b) for(int i = int(b)-1; i >= int(a); i--)
const int MOD = 1e9 + 7;
#define pb push_back
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
#define se second
#define fi first
#define all(x) (x).begin() (x).end() 


int main(){

    int n, x; cin >> n >> x;

    vll dp(x+1);
    vpii v(n+1);
    int p;
    rep(i,1,n+1){
        cin >> v[i].fi;
    }
    rep(i,1,n+1){
        cin >> v[i].se;
    }
    v[0].fi = 0;
    v[0].se = 0;
   
    rep(i,1,n+1){
        //dbgvec(dp);
        per(j,v[i].fi,x+1){
            if(j-v[i].fi >= 0)
                dp[j] = max(dp[j],v[i].se + dp[j-v[i].fi]);
        }
    }
    //dbgvec(dp);

    cout << dp[x] << endl;

}