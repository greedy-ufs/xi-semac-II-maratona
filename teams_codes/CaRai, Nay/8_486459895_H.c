#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, q, t, acc=0, ans=0;
    uint32_t m;
    scanf("%d %d %d", &n, &q, &t);
    scanf("%u", &m);
    for (int i=0; i<q; i++){
        uint32_t config;
        scanf("%u", &config);
        uint32_t resultado = config ^ m;
        while (resultado >= 2){
            uint32_t resto = resultado % 2;
            if (resto == 1){
                acc++;
            }
            resultado = resultado / 2;
        }
        if (resultado == 1){
            acc++;
        }
        if (acc <= t){
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}