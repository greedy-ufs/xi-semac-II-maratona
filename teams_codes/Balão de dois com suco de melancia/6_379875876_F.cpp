#include <bits/stdc++.h>
using namespace std;

int solve(int n, int a, int t){
    int ans = (n/a) * t;
    if (n%a>0){
        
        ans+=t;
    }    

    return ans; 

}

int main()
{
    ios::sync_with_stdio(false);

    vector<int> data(3);
    for (int i = 0; i < 3; i++) cin >> data[i];

    cout << solve(data[0], data[1], data[2]) << endl;
}