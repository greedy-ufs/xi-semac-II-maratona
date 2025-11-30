#include<bits/stdc++.h>

using namespace std;

int main() {

    int n; cin >> n;

    int k = n;
    long long sum = 0;

    while(n--) {
        int x; cin >> x;
        sum += x;

    }



    if(sum % k == 0) {
        cout << "SIM" << "\n";
    } else {
        cout << "NAO" << "\n";
    }

    return 0;
}