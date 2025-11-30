#include <bits/stdc++.h>
using namespace std;

#define int long long
#define dbg(v) cerr << #v << " = " << v << "\n"
#define fall(i, s, n) for(int i=s; i<n; i++)
#define rfall(i, s, n) for(int i=s; i>=n; i--)

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, t,a ; cin >> n;
    int e = 0;

    for(int r = 0;r < n;r++){
        cin >> a;
        e += a;
    }

    if(e%n==0) cout << "SIM";
    else cout << "NO";
    cout << endl;
}