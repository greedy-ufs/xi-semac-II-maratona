#include <bits/stdc++.h>

using namespace std;

int main() {

    int n; cin >> n;
    int total = 0;


    for(int i =0; i < n; i++) {
        int x; cin >> x;
        if(x == 3) {
            total++;
        }
    }

    

    cout << total << endl;



    return 0;
}