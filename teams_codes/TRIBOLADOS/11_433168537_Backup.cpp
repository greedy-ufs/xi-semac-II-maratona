#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define dbg(v) cerr << #v << " = " << v << "\n"
#define fall(i, s, n) for(int i=s; i<n; i++)
#define rfall(i, s, n) for(int i=s; i>=n; i--)

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string a, b; cin >> a >> b;

    int n=a.size(), m=b.size();

    bool flag=0;

    fall(i, 0, m-n){
        int err=0;

        fall(j, i, i+n+1){
            if(j-i-err == 0 && a[j-i-err] != b[j]){ err=2; break; }

            err += (a[j-i-err] != b[j]);

            if(err == 2 || j+1-i-err >= n) break;
            if(j == m-1 && i+n >= m && j+1-i-err != n){ err=2; break; }
        }

        flag |= (err < 2);
    }

    cout << (flag ? "MUITO FACIL" : "NAO MUITO FACIL") << "\n";
}