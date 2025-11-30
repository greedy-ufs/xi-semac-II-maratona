#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<int> fib(1e5 + 5, 0);

int solve(int k)
{
    if (k == 0 || k == 1) return 1;
    fib[0] = 1; fib[1] = 1;

    for (int i = 2; i <= k; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[k - 1] % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    
    cout << solve(k) << endl;
}