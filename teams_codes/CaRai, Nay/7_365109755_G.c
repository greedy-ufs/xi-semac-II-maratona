#include <stdio.h>
#include <stdlib.h>
int main(){
    long long int n;
    scanf("%lld", &n);
    long long int config = 0;
    long long int resp = 0;
    for (int i=0; i<n; i++){
        scanf("%lld ", &config);
        resp += config;
    }
    if (resp % n == 0) printf("SIM\n");
    else printf("NAO\n");
    return 0;
}