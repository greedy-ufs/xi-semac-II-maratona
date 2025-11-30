#include <stdio.h>
#include <math.h>

unsigned long int lista[1000001];

unsigned long int fibonachi(int n,unsigned long int lista[]){
    if (n == 0){
        return 0;
    }else{
        if (n == 1){
            return 1;
        }else{
            if(lista[n] != 0){
                return lista[n];
            }else{
            lista[n] = (fibonachi(n-1,lista) + fibonachi(n-2,lista));
            return lista[n];
            }
        }
    }
}

int main(){
    int num;
    scanf("%d",&num);

    for(int i = 0; i < 100001;i++){
        lista[i] = 0;
    }

    int deisanove = pow(10,9);
    int deisanovemaissete = deisanove+7;

    unsigned long int saida = (fibonachi(num,lista));
    saida = saida%deisanovemaissete;
    printf("%ld\n",saida);
    //printf("%d\n",deisanovemaissete);
    return 0;
}