#include<bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    int out = 0;

    while(n--) {
        int x;
        cin >> x;

        if(x == 3) {
            out++;
        }
    }

    cout << out << '\n';

    return 0;
}