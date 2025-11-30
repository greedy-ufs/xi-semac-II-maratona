#include <bits/stdc++.h>
using namespace std;

int main () {

    int n, c = 0;

    cin >> n;

    int e[n];

    for (int i = 0; i < n; i++) {

        cin >> e[i];

        if (e[i] == 3) {
            c++;
        }
    }

    cout << c << endl;

    return 0;
}