#include <bits/stdc++.h>

using namespace std;

vector<int> dp(100009,-1);
const long long MOD = 1e9 + 7;

long long fib(int n){
    if(n==0) return 1;
    if(n==1)return 1;
    else if(dp[n] != -1) return dp[n];

    return fib(n-1) + fib(n-2);
}

int main(){
    int k; cin >> k;
    k--;
    dp[0]=1;
    dp[1]=1;
    cout << fib(k) % MOD << '\n';
}