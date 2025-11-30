#include <stdio.h>
#include <stdlib.h>
int main(){
    long long int fib;
    long long int x1=1;
    long long int x2 =1;
    long long res;
    scanf("%lld",&fib);
    if (fib == 1 || fib == 0){
        res = 1%(10**9 + 7);
    }
    else{
        for(long long int i=1;i<fib;i++){
            long long int aux=x1;
            x1=x2;
            x2=aux+x1;
        }
        res = x2%(10**(9)+7);
    }
    
    printf("%lld\n",res);
    return 0;
}