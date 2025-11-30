#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define dbg(v) cerr << #v << " = " << v << "\n"
#define fall(i, s, n) for(int i=s; i<n; i++)
#define rfall(i, s, n) for(int i=s; i>=n; i--)

const int MAXN = 3e6+7;
const int e=1e6+1;

struct line{
    int x, y1, y2;
    bool beg;

    const bool operator<(const line& b){
        if(x != b.x) return x < b.x;
        if(y1 == y2 && beg && b.y1 != b.y2) return 0;
        if(y2 != y1 && b.y1 == b.y2 && !b.beg) return 0;
        //else if(y2-y1 != b.y2-b.y1) return y2-y1 < b.y2-b.y1;
        //else return beg < b.beg;
        else return 1;
    }
};

int bit[MAXN];

vector<line> v;

void upd(int x, int v){
    while(x < MAXN) bit[x] += v, x += (x&(-x));
}

int qry(int x){
    int sum=0;

    while(x > 0) sum += bit[x], x -= (x&(-x));

    return sum;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    fall(i, 0, n){
        int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;

        x1 += e, x2 += e, y1 += e, y2 += e;

        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);

        v.pb({x1, y1, y2, 1}), v.pb({x2, y1, y2, 0});
    }

    sort(v.begin(), v.end());

    int cnt=0;

    for(auto& [x, y1, y2, beg] : v){
        if(y1 != y2 && beg){
            cnt += qry(y2-1)-qry(y1);
        }else if(y1 == y2){
            if(beg) upd(y1, 1);
            else upd(y1, -1);
        }
    }

    cout << cnt << "\n";
}