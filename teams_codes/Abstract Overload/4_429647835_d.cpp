#include <bits/stdc++.h>

using namespace std;

int main() {

    int k; cin >> k;
    int total = 1;

    vector<int> primeiros(k);
    vector<int> segundos(k);

    for(int i = 0; i < k; i++) {
        cin >> primeiros[i] >> segundos[i];
    }
    for(int j=1; j<k; j++){
        if(primeiros[j] != primeiros[j-1]) total++;
    }

    cout << total << endl;

    return 0;
}