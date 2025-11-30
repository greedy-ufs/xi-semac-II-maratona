#include <stdio.h>
#include <stdlib.h>
int main(){
    long long int fib;
    long long int x1 = 0;
    long long int x2 = 1;
    long long int res;
    scanf("%lld", &fib);
    if (fib == 1 || fib == 2){
        res = 1;
    } 
    else if (fib == 0){
        res = 0;
    }
    else {
        for(long long int i=2; i<fib; i++){
            long long int aux = x1;
            x1 = x2;
            x2 = aux+x1;
        }
        res = x2 % ((10*10*10*10*10*10*10*10*10)+7);
    }

    printf("%lld\n",res);
    return 0;
}