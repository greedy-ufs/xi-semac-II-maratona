#include <stdio.h>

int main(){
    int Qnt;
    scanf("%d",&Qnt);
    int max = 0;

    for(int i=0;i<Qnt;i++){
        int m;
        scanf("%d",&m);
        max += m;
    }

    if((max%Qnt) == 0){
        printf("SIM\n");
    }else{
        printf("NAO\n");
    }

}