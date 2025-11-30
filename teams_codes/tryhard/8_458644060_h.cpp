#include <bits/stdc++.h>

using namespace std;


int main(){
    long long n,q,t;
    cin >> n >> q >> t;
    long long m; cin >> m;
    long long ans=0;
    for(int i=0;i<q;i++){
        long long x; cin >> x;
        long long sum=0;
        int tempA=x;
        int tempB=m;
        for(int i=1;i<32;i++){
            if(tempA <=0 && tempB <=0) break;
            int last = (tempA&1);
            int pLast= (tempB&1);
            if(last != pLast)sum++;
            tempA = (tempA >> i);
            tempB = (tempB >> i);
        }
        if(sum <= t)ans++;
    }

    cout << ans << '\n';

    return 0;
}