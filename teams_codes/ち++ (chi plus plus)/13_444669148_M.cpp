#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define endl '\n'
#define dbg(x) (cout << #x << " = " << x << endl)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll MAX = 0;
ll n,t;
vector<ll> temp;

ll solve(ll num){
    ll acc = 0;
    for(ll i = 0; i < n; i++ ){
        acc += (num/temp[i]);
    }
    // dbg(acc);
    // sleep(1);
    return acc;
}

int main(){
    cin >> n >> t;
    for(ll i = 0; i < n; i++){
        ll num; cin >> num;
        if(num > MAX) MAX = num;
        temp.push_back(num);
    }
    ll l = 0, r = (MAX*t) + 1, m;
    while(l <= r){
        m = (l+r)/2;
        ll ans = solve(m);
        // dbg(m);
        if(ans == t) break;
        else if(ans < t) l = m + 1;
        else r = m - 1; 
    }
    
    cout << m << endl;
    return 0;
}