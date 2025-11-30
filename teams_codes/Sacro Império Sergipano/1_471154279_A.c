#include <stdio.h>
#include <math.h>

unsigned long int lista[1000001];

unsigned long int fibonachi(int n,unsigned long int lista[]){
    if (n == 0){
        return 1;
    }else{
        if (n == 1){
            return 1;
        }else{
            if(lista[n] != 0){
                return lista[n];
            }else{
            lista[n] = (fibonachi(n-1,lista) + fibonachi(n-2,lista)) % 1000000007;
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

    
    unsigned long int saida = (fibonachi(num-1,lista));
    
    printf("%ld\n",saida);
    //printf("%d\n",deisanovemaissete);
    return 0;
}