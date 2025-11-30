#include <bits/stdc++.h>
using namespace std;


#define rep(i,a,b) for(int i = int(a); i < int(b); i++)
const int MOD = 1e9 + 7;

typedef vector<int> vi;

int main(){

    int n; cin >> n;

    vi v(n+1);
    v[1] = 1;
    v[2] = 1;

    rep(i,2,n+1)
        v[i] = (v[i-1] + v[i-2]) % MOD;
    
    cout << v[n] << endl;

    return EXIT_SUCCESS;

}