#include <bits/stdc++.h>
#define ll long long

using namespace std;

long long fibo(ll n)
{
    ll dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (ll i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int main()
{
    ll num;
    cin >> num;
    cout << fibo(num) << endl;
    return 0;
}