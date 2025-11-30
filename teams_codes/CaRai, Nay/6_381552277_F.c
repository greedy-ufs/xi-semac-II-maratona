#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, a, t, ans;
    scanf("%d %d %d", &n, &a, &t);
    int x = n / a;
    if (x % 2 == 0){
        ans = x * t;
    } else {
        ans = (x * t) + t;
    }
    printf("%d\n", ans);
    return 0;
}