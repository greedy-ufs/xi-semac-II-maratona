#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define endl '\n'
#define dbg(x) (cout << #x << " = " << x << endl)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){

    int n, acc = 0; cin >> n;
    while(n--){
        int num; cin >> num;
        if(num == 3) acc++;
    }
    cout << acc << endl;
    return 0;
}