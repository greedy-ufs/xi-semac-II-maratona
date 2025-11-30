#include <bits/stdc++.h>

using namespace std;

vector<long long> dp(100009,-1);
const int MOD = 1e9 + 7;

long long fib(long long n){
    if(dp[n]!=-1) return dp[n];
    if(dp[n-1] !=-1 && dp[n-2]!=-1) {
        dp[n] = dp[n-1]+dp[n-2];
        return dp[n];
    }
    return  fib(n-1) + fib(n-2);
    
}

int main(){
    int k; cin >> k;
    if(k==0) {
        cout << 1 <<'\n';
        return 0;
    }
    k--;
    dp[0]=1;
    dp[1]=1;
    long long ans = fib(k) % MOD;
    cout << ans << '\n';
}