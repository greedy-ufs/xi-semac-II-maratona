#include <stdio.h>

int fibonachi(int n){
    if (n == 0){
        return 0;
    }else{
        if (n == 1){
            return 1;
        }else{
            return(fibonachi(n-1) + fibonachi(n-2));
        }
    }
}

int main(){
    int num;
    scanf("%d",&num);
    
    printf("%d\n",(fibonachi(num))%(1000000007));

    return 0;
}