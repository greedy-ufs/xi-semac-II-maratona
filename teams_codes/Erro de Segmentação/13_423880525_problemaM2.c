#include <stdio.h>

int main()
{
    long long N, T;
    scanf("%lld %lld", &N, &T);
    long long lista[N];
    long long ld = 0;
       for(int i = 0; i < N; i++)
    {
        scanf("%lld", &lista[i]);
        ld += T * lista[i] / N;
    }

    
    long long le = 0;


    long long tempo = ld/2;
    while (ld - le > 0)
    {
        long long teste = 0;
        for(int i = 0; i < N; i++){
            teste += tempo/lista[i]; 
        }

        if(teste < T){
            le = tempo + 1;
            tempo += (ld - tempo) / 2;
            if(ld - le == 0) tempo+= 1;
            
        } else if(teste > T)
        {
            ld = tempo - 1;
            tempo = (tempo - le) / 2;
        }
        else{
            break;
        }
    }
    
    printf("%lld\n", tempo);


}


/*
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

*/