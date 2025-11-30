#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    int config = 0;
    int resp = 0;
    for (int i=0; i<n; i++){
        scanf("%d ", &config);
        if (config == 3)
            resp++;
    }

    printf("%d\n", resp);
    return 0;
}