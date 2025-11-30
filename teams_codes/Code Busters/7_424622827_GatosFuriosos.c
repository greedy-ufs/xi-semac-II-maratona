#include <stdio.h>

int main() {
	
	long int N;
	long int soma = 0;
	scanf("%ld",&N);
	
	for(long int j=1; j<=N; j++){
		long int n2;
		scanf("%ld",&n2);
		soma+=n2; 
	}
	
	if ((soma%N)!=0){
		printf("NAO\n");
	}
	else {
		printf("SIM\n");
	}
	
	return 0;
	
}
