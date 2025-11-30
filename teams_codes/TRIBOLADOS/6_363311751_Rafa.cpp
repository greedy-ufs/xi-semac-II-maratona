#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fir first
#define sec second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;
const int inf = 0x6f6f6f6f;

int n, T, ans,a,m;
pii it[MAXN];

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> a;

    int e = n/m;
    if(n%m!=0) e++;

    cout << a*e << endl;
}