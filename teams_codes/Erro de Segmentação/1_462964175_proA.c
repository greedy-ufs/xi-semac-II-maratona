#include <stdio.h>


int main(){
    long ant = 1, prox = 1;
    long n;
    scanf("%ld", &n);

    for (long i = 2; i < n; i++){
        long temp = prox;
        prox += ant;
        ant = temp;
    }

    prox = prox % (1000000000 + 7);

    if(n == 0)
        printf("0\n");
    else
        printf("%ld\n", prox);

    return 0;
}