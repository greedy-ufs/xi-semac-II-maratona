#include<bits/stdc++.h>

using namespace std;

int main() {

    int n, a, t;
    cin >> n >> a >> t;

    int res = (n/a) * t;

    if(n%a) {
        res += t;
    }

    cout << res << '\n';

    return 0;
}