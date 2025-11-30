#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define dbg(v) cerr << #v << " = " << v << "\n"
#define fall(i, s, n) for(int i=s; i<n; i++)
#define rfall(i, s, n) for(int i=s; i>=n; i--)

const int MAXN = 1e5+7;

int dp[MAXN], dp2[MAXN]; // dp[i] = any seq at i, dp2[i] = not start with i

int a[MAXN];

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string a,b;
    cin >> a >> b;

    int l = 0;
    bool t = false;
    int e = 0;
    for(int r = 0;r < b.size();r++){
        if(l==a.size()) t = true;
        if(b[r]==a[l] and e<=1){ 
            l++;
        }
        else{ 
            if(l!=0){
                e++;
            }
            else{ 
                l = 0;
                e = 0;
            }
        }
        //cerr << l << " ";
    }    
    cerr << endl;

    if(t) cout << "MUITO FACIL";
    else cout << "NAO MUITO FACIL";
    cout << endl;
}