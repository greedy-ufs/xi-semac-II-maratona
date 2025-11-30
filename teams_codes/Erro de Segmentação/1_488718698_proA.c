#include <stdio.h>


int main(){
    long ant = 1, prox = 1;
    long n;
    scanf("%ld", &n);

    if(n == - 1) {
        printf("0\n");
        return 0;
    }
    for (long i = 1; i < n; i++){
        long temp = prox;
        prox += ant;
        ant = temp;
    }

    prox = prox % (1000000000 + 7);


    printf("%ld\n", prox);

    return 0;
}