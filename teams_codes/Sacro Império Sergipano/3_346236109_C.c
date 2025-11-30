#include <stdio.h>

int main(){
    int n;
    int atual = 0;
    int count = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &atual);
        if (atual == 3)
        {
            count++;
        }
    }
    
    printf("%d\n", count);
}