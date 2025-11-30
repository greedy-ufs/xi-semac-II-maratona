#include <stdio.h>

int main(){
    int lembrancinhas, nArtesoes, segundoAtual=0;
    int count = 0;
    scanf("%d %d", &nArtesoes, &lembrancinhas);

    int artesao[nArtesoes];
    int copiaArtesao[nArtesoes];

    for (int i = 0; i < nArtesoes; i++)
    {
        scanf("%d", &artesao[i]);
    }

    for (int i = 0; i < nArtesoes; i++)
    {
        copiaArtesao[i] = artesao[i];
    }
    
    for(; count < lembrancinhas; segundoAtual++){
        for(int i = 0; i < nArtesoes; i++){
            if(artesao[i] == segundoAtual){
                artesao[i] += copiaArtesao[i];
                count++;
            }
        }
    }
        

    segundoAtual--;
    printf("%d\n", segundoAtual);
    return 0;
}

