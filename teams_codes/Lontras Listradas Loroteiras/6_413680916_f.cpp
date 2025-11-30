#include <bits/stdc++.h>
using namespace std;

int main () {

    int n, a, t, ttotal;

    cin >> n >> a >> t;

    if (n % a == 0) {
        ttotal = n / a * t;
    } else {
        ttotal = (n / a * t) + t;
    }

    cout << ttotal << endl;

    return 0;
}