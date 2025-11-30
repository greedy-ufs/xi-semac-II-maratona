#include <bits/stdc++.h>

using namespace std;

vector<long long> dp(100009,-1);
const int MOD = 1e9 + 7;

int main(){
    int k; cin >> k;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=k;i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    long long ans = dp[k] % MOD;
    cout << ans << '\n';
}