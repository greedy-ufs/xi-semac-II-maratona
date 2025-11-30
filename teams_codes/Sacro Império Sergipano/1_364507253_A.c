#include <stdio.h>

long int fibonachi(int n,int lista[]){
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
    int lista[100000];
    int saida = (fibonachi(num,lista))%(1000000007);
    
    printf("%ld\n",saida);

    return 0;
}