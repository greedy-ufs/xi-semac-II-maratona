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

    printf("%ld\n", prox);

    return 0;
}