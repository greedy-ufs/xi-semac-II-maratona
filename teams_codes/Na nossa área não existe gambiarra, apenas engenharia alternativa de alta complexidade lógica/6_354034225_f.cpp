#include <bits/stdc++.h>
using namespace std;


#define rep(i,a,b) for(int i = int(a); i < int(b); i++)
const int MOD = 1e9 + 7;

typedef vector<int> vi;
typedef long long ll;

int main(){

    int n, a, t; cin >> n >> a >> t;

    int k = ceil(n * 1.0/a);
    //cout << k << endl;
    int r = k*t;

    cout << r << endl;

}