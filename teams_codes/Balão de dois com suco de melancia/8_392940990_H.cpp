#include <bits/stdc++.h>
using namespace std;

int solve(int M, int P, int N, int T)
{
    int bits_diff = P ^ M;

    if (bits_diff == 0) return 1;

    int diff = 0;

    for (int i = 0; i < N; i++)
    {
        if (0b1 & bits_diff) diff++;

        if (diff > T) return 0;

        bits_diff = bits_diff >> 1;
    }
    
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    int N, Q, T; cin >> N >> Q >> T;
    int M; cin >> M;

    int ans = 0;

    while(Q--)
    {
        int P; cin >> P;
        ans += solve(M, P, N, T);
    }

    cout << ans << endl;

    return 0;
}