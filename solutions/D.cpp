#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    });
    int temp = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].first >= temp) {
            cnt++;
            temp = v[i].second;
        }
    }
    cout << cnt << endl;
}