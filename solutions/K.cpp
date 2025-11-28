#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> compute_pi(const string& P) {
    int m = P.size();
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];
        if (P[i] == P[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> get_prefix_matches(const string& T, const string& P, const vector<int>& pi) {
    int n = T.size();
    int m = P.size();
    vector<int> matches(n, 0);
    
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && T[i] != P[j])
            j = pi[j - 1];
        if (T[i] == P[j])
            j++;
        
        matches[i] = j;
        
        if (j == m) {
            j = pi[j - 1];
        }
    }
    return matches;
}

void solve() {
    string M, S;
    
    cin >> M >> S;

    int n = S.size();
    int m = M.size();

    if (n < m) {
        cout << "NAO MUITO FACIL" << endl;
        return;
    }

    vector<int> pi_M = compute_pi(M);
    vector<int> pref_len = get_prefix_matches(S, M, pi_M);

    string M_rev = M;
    reverse(M_rev.begin(), M_rev.end());
    
    string S_rev = S; 
    reverse(S_rev.begin(), S_rev.end());
    
    vector<int> pi_M_rev = compute_pi(M_rev);
    vector<int> suff_len_rev = get_prefix_matches(S_rev, M_rev, pi_M_rev);
    
    vector<int> suff_len(n, 0);
    for(int k = 0; k < n; ++k) {
        suff_len[n - 1 - k] = suff_len_rev[k];
    }

    bool aprovado = false;

    for (int j = 1; j < n; j++) {
        int i_gap0 = j - 1;
        if (i_gap0 >= 0) {
            if (pref_len[i_gap0] > 0 && suff_len[j] > 0 && 
                (pref_len[i_gap0] + suff_len[j] == m)) {
                aprovado = true;
                break;
            }
        }

        int i_gap1 = j - 2;
        if (i_gap1 >= 0) {
            if (pref_len[i_gap1] > 0 && suff_len[j] > 0 && 
                (pref_len[i_gap1] + suff_len[j] == m)) {
                aprovado = true;
                break;
            }
        }
    }

    if (aprovado) 
        cout << "MUITO FACIL" << endl;
    else 
        cout << "NAO MUITO FACIL" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}