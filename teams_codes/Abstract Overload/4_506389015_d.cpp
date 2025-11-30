#include <bits/stdc++.h>

using namespace std;

int main() {

    int k; cin >> k;
    int total = 0;

    vector<pair<int,int>> p;


    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        p.push_back({x,y});

    }
    bool ruim = false;
    for(int i=0; i<k; i++){
        for(int j=0; j < k; j++) {
            if(p[i].first < p[j].first && p[i].first < p[j].second) {
                ruim = true;
            } else {
                ruim = true;
            }
        }
        if(ruim == true) {
            total++;
        }
    }

    cout << total << endl;

    return 0;
}