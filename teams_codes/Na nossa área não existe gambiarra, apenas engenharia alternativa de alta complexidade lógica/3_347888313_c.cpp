#include <bits/stdc++.h>
using namespace std;


#define rep(i,a,b) for(int i = int(a); i < int(b); i++)
const int MOD = 1e9 + 7;

typedef vector<int> vi;

int main(){

    int n;
    cin >> n;
    int acc = 0;
    int var;

    for(int i = 0; i < n; i++){
        cin >> var;
        if(var == 3)
            acc++;
    }

    cout << acc << endl;

    return EXIT_SUCCESS;

}