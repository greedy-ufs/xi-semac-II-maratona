#include <stdio.h>
#include <string.h>

int main(){
    int lembrancinhas, nArtesoes, segundoAtual;
    int count = 0;
    int min = 1000000000;
    scanf("%d %d", &nArtesoes, &lembrancinhas);

    
    int artesao[nArtesoes];
    int copiaArtesao[nArtesoes];

    for (int i = 0; i < nArtesoes; i++)
    {
        scanf("%d", &artesao[i]);
        if(artesao[i] < min){
            min = artesao[i];
        }
    }
    segundoAtual = min;
    memcpy(copiaArtesao,artesao,4*nArtesoes);
    //for (int i = 0; i < nArtesoes; i++)
    //{
    //    printf("%d",copiaArtesao[i]);
    //}
    
    for(; count < lembrancinhas; segundoAtual = segundoAtual + min){
        for(int i = 0; i < nArtesoes; i++){
            while(artesao[i] <= segundoAtual){
                artesao[i] += copiaArtesao[i];
                count++;
            }
        }
    }
        

    segundoAtual = segundoAtual - min;
    printf("%d\n", segundoAtual);
    return 0;
}

