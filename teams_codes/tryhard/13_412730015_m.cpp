#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,t; cin >> n>> t;
    vector<int> a(n);
    for(auto &x: a) cin >> x;

    int time=1;
    int ans=0;
    while(true){
        for(int i=0;i<n;i++){
            if(time % a[i] == 0) ans++;
            if(ans==t)break;
        }
        if(ans==t)break;
        time++;
        
    }

    cout << time << '\n';

    return 0;
}