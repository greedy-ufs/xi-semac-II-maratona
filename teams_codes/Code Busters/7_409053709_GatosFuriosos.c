#include <stdio.h>

int main() {
	
	int N;
	int soma = 0;
	scanf("%d",&N);
	
	for(int j=1; j<=N; j++){
		int n2;
		scanf("%d",&n2);
		soma+=n2; 
	}
	
	if((soma%N)!=0){
		printf("NAO\n");
	}
	else{printf("SIM\n");}
	
	return 0;
	
}
