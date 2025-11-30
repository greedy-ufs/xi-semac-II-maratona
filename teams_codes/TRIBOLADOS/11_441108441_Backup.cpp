#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define dbg(v) cerr << #v << " = " << v << "\n"
#define fall(i, s, n) for(int i=s; i<n; i++)
#define rfall(i, s, n) for(int i=s; i>=n; i--)

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string a, b; 
    cin >> a >> b;

    bool t = 0;
    for(int r = 0;r < b.size();r++){
        int e = 0;
        int l = 0;
        int ri = r;
        if(b[ri]!=a[l]) continue;
        while(true){
            if(l==a.size()){
                t = 1;
                break;
            }
            if(b[ri]==a[l] and e <= 1){
                l++;
            }
            else{
                e++;
            }

            if(e==2) break;
            ri++;
        }
        if(t) break;
    }
    if(t) cout << "MUITO FACIL";
    else cout << "NAO MUITO FACIL";
    cout << endl;
}