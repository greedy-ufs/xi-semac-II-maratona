#include <stdio.h>

int main(){
    long long n;
    scanf("%lld ", &n);

    long long soma = 0;
    for(int i = 1; i < n; i++)
    {
        int num;
        scanf("%d ", &num);
        soma += num;
    }

    if((soma % n) == 0) printf("SIM\n");
    else printf("NAO\n");

}