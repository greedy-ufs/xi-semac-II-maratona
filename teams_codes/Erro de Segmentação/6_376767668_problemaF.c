#include <stdio.h>

int main()
{
    int N, A, T;
    scanf("%d %d %d", &N, &A, &T);

    int result = ((N / A) + (N % A)) * T;

    printf("%d\n", result);


    return 0;
}