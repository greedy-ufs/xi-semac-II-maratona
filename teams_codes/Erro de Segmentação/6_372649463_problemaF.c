#include <stdio.h>

int main()
{
    long long N, A, T;
    scanf("%d %d %d", &N, &A, &T);

    long long result = ((N / A) + (N % A)) * T;

    printf("%d\n", result);
    

    return 0;
}