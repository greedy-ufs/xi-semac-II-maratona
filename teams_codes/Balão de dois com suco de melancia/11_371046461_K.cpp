#include <bits/stdc++.h>
using namespace std;

void solve(string M, string S)
{
    int m = M.size(), s = S.size();

    int ptr_M = 0; int ptr_S = 0;
    int err = 0;

    while(ptr_S < s || (m - ptr_M) <= (s - ptr_S))
    {
        if (M[ptr_M] == S[ptr_S]) { ptr_M++; err = 0; }
        else err++;
            
        if (err > 1)
        {
            err = 0;
            ptr_M = 0;
        }

        ptr_S++;

        if (ptr_M >= m) {
            cout << "MUITO FACIL" << endl;
            return;
        }
    }

    cout << "NAO MUITO FACIL" << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    string M, S; cin >> M >> S;

    solve(M, S);

    return 0;
}