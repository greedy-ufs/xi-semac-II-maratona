#include <bits/stdc++.h>
using namespace std;

vector<long long> k(2 * 1e5 + 5);
vector<long long> lembrancas(2 * 1e5 + 5, 0);

void solve(vector<long long> arr, int t, int n)
{
    int passo = arr[0];
    int t_atual = 0;

    while(t >= 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (t_atual % k[i] == 0) {
                lembrancas[i]++;
                t--;
            }
        }

        t_atual += passo;
    }

    cout << t_atual << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; i++)
        cin >> k[i];

    sort(&k[0], &k[n - 1]);
    
    
    return 0;
}