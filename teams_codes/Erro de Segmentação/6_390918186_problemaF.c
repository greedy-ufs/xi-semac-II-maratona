#include <stdio.h>

int main()
{
    int N, A, T;
    scanf("%d %d %d", &N, &A, &T);

    int result = ((N / A)) * T;
    if( (N % A) != 0) result += T; 

    printf("%d\n", result);


    return 0;
}