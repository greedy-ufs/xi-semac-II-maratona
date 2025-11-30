#include <bits/stdc++.h>

using namespace std;

vector<long long> dp(100009,-1);
const int MOD = 1000000000+7;

int fib(int n){
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-2]+dp[i-1];
    }
    return dp[n];
}

int main(){
    int k; cin >> k;
    cout << fib(k) % MOD<< '\n';
}