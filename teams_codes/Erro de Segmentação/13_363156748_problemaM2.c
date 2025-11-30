#include <stdio.h>

int main()
{
    int N, T;
    scanf("%d %d", &N, &T);
    long long lista[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &lista[i]);
    }

    long long tempo = 0;
    while(T > 0)
    {
        tempo++;
        for(int i = 0; i < N; i++)
        {
            if((tempo % lista[i]) == 0 ) --T;
        }
        
    }

    printf("%lld\n", tempo);

}