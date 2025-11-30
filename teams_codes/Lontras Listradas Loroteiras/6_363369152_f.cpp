#include <bits/stdc++.h>
using namespace std;

int main () {

    int n, a, t, ttotal;

    cin >> n >> a >> t;

    ttotal = ((n / a) * t) + ((n % a)/(n % a) * t);

    cout << ttotal << endl;

    return 0;
}