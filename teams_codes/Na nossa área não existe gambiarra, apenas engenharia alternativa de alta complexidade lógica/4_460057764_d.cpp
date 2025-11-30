#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x << " = " << x << endl;
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
#define all(x) (x).begin(), (x).end() 


int main(){

    int n; cin >> n;

    vpii v(n);
    for(auto& [a,b] : v){
        cin >> b;
        cin >> a;
    }
    
    sort(all(v));
    int j = v[n-1].fi;
    int i = v[n-1].se;

    int acc = 1;

    per(k,0,n-1){
        // dbg(i);
        // dbg(j);
        // cout << "--" << endl;
        if(v[k].fi < j && v[k].se > i){
            j = v[k].fi;
            i = v[k].se;
            continue;
        }
        if(v[k].fi > i)
            continue;


        j = v[k].fi;
        i = v[k].se;
        acc++;
    }
    // dbg(i);
    // dbg(j);

    cout << acc << endl;
}