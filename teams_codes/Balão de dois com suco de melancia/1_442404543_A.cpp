#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<long long> fib(1e5 + 5, 1);

long long solve(long long k)
{
    for (int i = 2; i <= k; i++)
    {
        fib[i] = (fib[i - 1] % MOD) + (fib[i - 2] % MOD);
    }

    return fib[k-1] % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    
    cout << solve(k) << endl;
    
    return 0;
}