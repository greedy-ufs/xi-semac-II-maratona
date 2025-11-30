#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int cont = 0;
    for (int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        if (temp == 3) cont++;
    }

    printf("%d\n", cont);
    
    return 0;
}