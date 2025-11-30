#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define endl '\n'
#define dbg(x) (cout << #x << " = " << x << endl)

typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll mod = 1e9 + 7;
ll MAX =  1e5 + 10;
vector<ll> fibs(MAX,0);


ll fib(ll num){
    if(fibs[num] != 0 && num > 0) return fibs[num];
    if(num == 0 || num == 1){
        // cout << "base" << endl;
        return 1;
    } 
    else {
        ll ans = fib(num-1) + fib(num-2);
        if(num > 0) fibs[num] = ans%mod;
        return fibs[num];
    }
}

// void printar(int n){
//     for(int i = 0; i < n; i++){
//         cout << fibs[i] << " ";
//     }
//     cout << endl;
// }
// 1 1 2 3 5 8 13  
int main(){

    ll k; cin >> k;
    fibs[0] = 1;
    fibs[1] = 1;
    fib(k);
    ll ans  = k == 0 ? 0 : fibs[k - 1];
    ll resp = ans;
    // printar(k);
    cout << resp << endl;
    return 0;
}