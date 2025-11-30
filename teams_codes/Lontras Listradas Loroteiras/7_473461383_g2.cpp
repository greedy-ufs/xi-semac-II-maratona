#include <bits/stdc++.h>
using namespace std;

int main () {

    int n;
    cin >> n;
    int p[n], s = 0;

    if (n == 0) {
        cout << "SIM" << endl;

    } else {

        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        for (int i = 0; i < n; i++){
            s += p[i];
            cout << s << endl;
        }

        if (s % n == 0 && s >= 0 ) {
            cout << "SIM" << endl;
        } else {
            cout << "NAO" << endl;
        }
        }
    
    return 0;
}
