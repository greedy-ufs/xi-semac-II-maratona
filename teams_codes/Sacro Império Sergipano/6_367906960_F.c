#include <stdio.h>



int main(){
    int n,a,t;
    int saida, sobra;
    scanf("%d %d %d",&n,&a,&t);

    sobra = n%a;
    if(sobra > 0){
        saida = (((n-sobra)/a)+1)*t;
    }else{
        saida = (n/a)*t;
    }


    printf("%d\n",saida);
    return 0;
}