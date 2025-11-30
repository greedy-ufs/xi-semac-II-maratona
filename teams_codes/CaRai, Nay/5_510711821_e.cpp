#include <iostream>
#include <sstream>
#include <vector>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> x1;
    std::vector<int> y1;
    std::vector<int> x2;
    std::vector<int> y2;
    int i = 0;
    while(i < n){
        std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    v1 = 0;
    v2 = 1;
    acc = 0;
    while(v1 < n - 1){
        if(x1[v1]<=x1[v2] && y1[v1]>=y1[v2]&& x2[v1]>=x2[v2]&& y2[v1]<=y2[v2])
            acc += 1;
        v2+=1;
        if(v2 == n - 1) {
            v1+=1;
            v2=v1+1;
        }
    }
    return 0;
}