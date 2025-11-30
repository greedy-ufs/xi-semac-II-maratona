#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define endl '\n'
#define dbg(x) (cout << #x << " = " << x << endl)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll n,q,t, m;

int main(){

    ll acc = 0; cin >> n >> q >> t >> m;
    for(ll i = 0; i < q; i++){
        //ler as placas
        ll p, dif = 0; cin >> p;
        for(ll j = 0; j < n; j++){
            bool comp = (p & (0b1 << j)) == (m & (0b1 << j));
            if(!comp) dif++;
        }
        if(dif <= t) acc++;
    }
    cout << acc << endl;
    return 0;
}