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
    ll l = 0, r = (MAX*t), m;
    ll ans, ans2, ans3;
    while(l <= r){
        m = (l+r)/2;
        ans = solve(m);
        // ans3 = solve(r);
        // dbg(m);
        // dbg(ans);
        if(ans >= t){
            ans2 = solve(m - 1);
            if(ans == t){
                do{
                    ans2 = solve(m-1);
                    if(ans2 == t) m--;
                }while(ans2 == t);
            }
            if(ans2 < t) break;
            else r = m - 1;
        } 
        else if(ans < t) l = m + 1;
        // else r = m - 1; 
    }
    if(ans != t){
        
    }
    cout << m << endl;
    return 0;
}