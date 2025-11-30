#include <bits/stdc++.h>
using namespace std;

#define int long long
#define dbg(v) cerr << #v << " = " << v << "\n"
#define fall(i, s, n) for(int i=s; i<n; i++)
#define rfall(i, s, n) for(int i=s; i>=n; i--)

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, t; cin >> n >> t;

    int a[n];

    fall(i, 0, n) cin >> a[i];

    auto test = [&](int x){
        int sum=0;

        fall(i, 0, n){
            sum += x/a[i];

            if(sum >= t) break;
        }

        return sum >= t;
    };

    int l=1, r=1e18;

    while(l < r){
        int m=(l+r)/2;

        if(test(m)) r=m;
        else l=m+1;
    }

    cout << r << "\n";
}