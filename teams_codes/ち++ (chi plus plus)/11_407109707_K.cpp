#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define endl '\n'
#define dbg(x) (cout << #x << " = " << x << endl)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){

    string s1, s2;
    cin >> s1 >> s2;
    //tolerancia de 1 caractere
    int qnt = 0;
    int j = 0;
    for(int i = 0; i < s2.size(); i++){
        if(j == s1.size()){
            cout << "MUITO FACIL" << endl;
            return 0;
        } 
        if(s2[i] == s1[j]){
            j++;
            continue;
        }
        else if(qnt == 0){
            if(s2[i + 1] == s1[j]){
                j++;
                continue;
            } 
            qnt++;
        }
        else{
            j = 0;
            qnt = 0;
        }
    }
    cout << "NAO MUITO FACIL" << endl; 
    return 0;
}