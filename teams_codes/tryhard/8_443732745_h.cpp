#include <bits/stdc++.h>

using namespace std;

string bin(int m){
    string ans="";
    if(m==0) return ans="0";
    while(m > 0){
        int val = m%2;
        string c = to_string(val);
        ans += c;
        m/=2;
    }
    return ans;
}

int main(){
    int n,q,t;
    cin >> n >> q >> t;
    int m; cin >> m;
    string principal = bin(m);
    int ans=0;
    for(int i=0;i<q;i++){
        int x; cin >> x;
        string curr = bin(x);
        int tol=t;
        for(int i=0;i<curr.size();i++){
            if(i > principal.size()-1)break;
            if(curr[i] != principal[i]){
                tol--;
            }
        }
        tol -= abs((int)principal.size()- (int)curr.size());
        if(tol >= 0)ans++;
    }

    cout << ans << '\n';

    return 0;
}