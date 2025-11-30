#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define endl '\n'
#define dbg(x) (cout << #x << " = " << x << endl)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){

    int n; cin >> n;

    vector<int> nums(n);
    int acc = 0;
    for(int i = 0 ; i < n; i++){
        int num; cin >> num;
        nums[i] = num;
        acc += num;
    }
    int media = acc % n;
    // while(acc > n){
    //     acc -=n ;
    // }
    string out = media == 0? "SIM" : "NAO";
    cout << out << endl;
    return 0;
}