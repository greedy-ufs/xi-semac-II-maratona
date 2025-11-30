#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int sum=0;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        sum+=x;
    }
    if(sum % n) cout << "NAO" << '\n';
    else cout << "SIM" << '\n';
    return 0;
}