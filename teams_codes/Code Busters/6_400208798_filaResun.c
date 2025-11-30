#include <stdio.h>

int main() {
	
	int N, A, T, rest, div;
	
	scanf("%d %d %d", &N, &A, &T);
	
	rest = N%A;
	div = N/A;
	int res= div*T;
	
	if (rest!=0) {
		div+=1;
		int resposta = div*T;
		printf("%d\n",resposta);
	} else {
		printf("%d\n",res);
	}
	return 0;
}	
