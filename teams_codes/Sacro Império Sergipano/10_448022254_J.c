#include <stdio.h>

int main(){

    int n,i,c;
    int bi = 1;
    scanf("%d",&n);
    for (int j = 0; j < n; j++)
    {
        scanf("%d %d",&i,&c);
        if( ((i%2==0) && (c%2==0)) || ((i%2==1) && (c%2==1))){
            if(bi == 1){
                bi = 0;
            }else{
                bi = 1; 
            }
        }
    }
    if(bi == 0){
        printf("Breno\n");
    }else{
        printf("Adversario\n");
    }
    

    return 0;
}