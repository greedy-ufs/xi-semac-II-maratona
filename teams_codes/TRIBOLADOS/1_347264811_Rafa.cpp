#include <bits/stdc++.h>
using namespace std;

#define int long long
#define dbg(v) cerr << #v << " = " << v << "\n"
#define fall(i, s, n) for(int i=s; i<n; i++)
#define rfall(i, s, n) for(int i=s; i>=n; i--)

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, t; cin >> n;
    int dp[200005];
    dp[0] = 1;
    dp[1] = 1;

    for(int r = 2;r <= n;r++){
        dp[r] = dp[r-1]+dp[r-2];
        dp[r] %= 1000000007;
        //cerr << dp[r] << " ";
    }

    cout << dp[n-1] << endl;
}