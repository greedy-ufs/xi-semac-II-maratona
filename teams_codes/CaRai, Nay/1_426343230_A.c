#include <stdio.h>
#include <stdlib.h>
int main(){
    long long int fib;
    long long int x1=1;
    long long int x2 =1;
    scanf("%lld",&fib);
    for(int i=0;i<fib;i++){
        long long int aux=x1;
        x1=x2;
        x2=aux+x2;
    }
    long long int res=x2%(10**(9)+7);
    printf("%lld\n",res);

    return 0;
}