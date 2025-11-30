#include <stdio.h>
#define ll long long



int main()
{
    ll le = 0, ld = 0;
    ll N, T;
    scanf("%lld %lld", &N, &T);

    ll lista[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%lld", &lista[i]);
        ld += lista[i];
    }

    ld = ld * N;

    ll tempo = ld / 2;
    while(ld - le > 0)
    {
        ll teste = 0;
        for(int i = 0; i < N; i++)
        {
            teste += tempo/lista[i];
        }

        if(teste < T)
        {
            le = tempo;
            tempo += (ld - le)/2;
            if((ld - le)% 2 != 0) {
                tempo += 1;
                le++;
            }
        }
        else if(teste > T)
        {
            ld = tempo;
            tempo -= (ld-le)/2;
        }
        else break;
    }

    printf("%lld\n", tempo);
}