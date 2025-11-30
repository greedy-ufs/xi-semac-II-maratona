#include <stdio.h>
#include <string.h>


int main(){
    char mestre[100001];
    char aluno[100001];
    
    scanf("%s\n%s",mestre,aluno);
    //printf("\n%s\n%s\n",mestre,aluno);
    int max = strlen(aluno);
    int maxA = strlen(mestre);
    int acerto = 0;
    int erro=0;

    for(int i = 0; i < max; i++){
        if(erro > 1){
            acerto = 0;
            erro = 0;
        }
        if(aluno[i] == mestre[acerto]){
            acerto++;
            //printf("\naluno acerto%c\n",aluno[i]);
        }else{
            if((acerto > 0) && (aluno[i] != mestre[acerto])){
                //printf("\naluno erro%c\n",aluno[i]);
                erro++;
            }
        }
        if(acerto == maxA){
            printf("MUITO FACIL\n");
            return 0;
        }
    }
    printf("NAO MUITO FACIL\n");
    return 0;
}