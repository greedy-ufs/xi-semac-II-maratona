#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve(int k)
{
    if (k == 0 || k == 1) {
        cout << 1 << endl;
        return;
    }

    vector<int> fib = { 1, 1 };
    
    for (int i = 2; i < k; i++)
    {
        int fib_n = fib[1] + fib[0];
        fib[0] = fib[1];
        fib[1] = fib_n;
    }

    cout << (fib[0] + fib[1]) % MOD << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    solve(k);
}