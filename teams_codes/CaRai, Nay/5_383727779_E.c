#include <stdio.h>
#include <stdlib.h>
int main(){
    long long int num;
    uint32_t x1;
    uint32_t y1;
    uint32_t x2;
    uint32_t y2;
    scanf("%lld", &num);
    uint32_t Ax1 = (uint32_t *)malloc(sizeof(uint32_t));
    uint32_t Ay1 = (uint32_t *)malloc(sizeof(uint32_t));
    uint32_t Ax2 = (uint32_t *)malloc(sizeof(uint32_t));
    uint32_t Ay2 = (uint32_t *)malloc(sizeof(uint32_t));
    for (int i=0; i<num; i++){
        scanf("%u %u %u %u", &Ax1[i], &Ay1[i], &Ax2[i], &Ay2[i]);
    }
    long long int v1=0;
    long long int  v2=1;
    long long int contador=0;
    while(v1<num-1){
        if(Ax1[v1]<=Ax1[v2] && Ay1[v1]>=Ay1[v2] && Ax2[v1]>=Ax2[v2] && Ay2[v1]<=Ay2[v2] ){
            contador++;
        }
        v2++;
        if(v2==num-1){
            v1++;
            v2=v1+1;
        }
    }
    printf("%lld\n",contador);
    return 0;
}