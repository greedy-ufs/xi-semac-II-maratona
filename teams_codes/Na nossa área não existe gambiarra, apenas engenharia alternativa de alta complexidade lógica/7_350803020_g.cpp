#include <bits/stdc++.h>
using namespace std;


#define rep(i,a,b) for(int i = int(a); i < int(b); i++)
const int MOD = 1e9 + 7;

typedef vector<int> vi;
typedef long long ll;

int main(){

    int n;
    cin >> n;
    ll acc = 0;
    ll var = 0;

    for(int i = 0; i < n; i++){
    cin >> var;
    acc += var;        
    }

    if(acc%n == 0)
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;
}