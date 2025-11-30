#include <bits/stdc++.h>

using namespace std;

int main() {

    int n; cin >> n;
    stack<int> s;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == 3) s.push(x);
    }

    cout << s.size() << endl;

    return 0;
}