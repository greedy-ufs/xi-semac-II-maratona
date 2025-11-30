#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n; cin >> n;
    long long sum=0;
    for(int i=0;i<n;i++){
        long long x; cin >> x;
        sum+=x;
    }
    if(sum % n == 0) cout << "SIM" << '\n';
    else cout << "NAO" << '\n';
    return 0;
}