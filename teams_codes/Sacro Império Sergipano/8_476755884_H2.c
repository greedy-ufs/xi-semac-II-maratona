#include <stdio.h>

int main(){
    int n, q, t, harmonicas = 0;
    int pm, p, comp, saida = 0;
    scanf("%d %d %d",&n,&q,&t);    
    scanf("%d",&pm);
    for(int i = 0; i < q; i++){
        scanf("%d",&p);
        comp = p^pm;
        if(comp & 1){
            saida++;
        }
        if(comp & 2){
            saida++;
        }
        if(comp & 4){
            saida++;
        }
        if(comp & 8){
            saida++;
        }
        if(comp & 16){
            saida++;
        }
        if(comp & 32){
            saida++;
        }
        if(comp & 64){
            saida++;
        }
        if(comp & 128){
            saida++;
        }
        if(comp & 256){
            saida++;
        }
        if(comp & 512){
            saida++;
        }
        if(comp & 1024){
            saida++;
        }
        if(comp & 2048){
            saida++;
        }
        if(comp & 4096){
            saida++;
        }
        if(comp & 8192){
            saida++;
        }
        if(comp & 16384){
            saida++;
        }
        if(comp & 32768){
            saida++;
        }
        if(comp & 65536){
            saida++;
        }
        if(comp & 131072){
            saida++;
        }
        if(comp & 262144){
            saida++;
        }
        if(comp & 524288){
            saida++;
        }
        //printf("\nsaida: %d",saida);
        if(saida <= t){
            harmonicas++;
        }
        saida = 0;
    }
    printf("%d\n",harmonicas);
    return 0;
}
