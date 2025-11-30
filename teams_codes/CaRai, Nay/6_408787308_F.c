#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, a, t, ans=0, qtd;
    scanf("%d %d %d", &n, &a, &t);
    qtd = n;
    while (qtd > 1){
        int x = qtd / a;
        if (qtd % a == 0){
            ans += x * t;
            qtd = 0;
        } else {
            ans += x * t;
            qtd -= x * a;
            a--;
        }
    }
    if (qtd == 1){
        ans += t;
    }
    /*
    qtd - 10
    x = 10 / 2 = 5
    ans += 5 * 3 = 15
    */
    //int x = n / a;
    /*if (n % a == 0){
        ans = x * t;
    } else {

        //ans = (x * t) + ((n % a) * t);
    }*/
    printf("%d\n", ans);
    return 0;
}