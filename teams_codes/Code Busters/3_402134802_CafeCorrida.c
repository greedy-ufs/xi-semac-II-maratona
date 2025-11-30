#include <stdio.h>

int main(){
	int n;
	int cont = 0;
	scanf("%d",&n);
	
	for(int j=1; j<=n; j++){
		int n2;
		scanf("%d",&n2);
		if(n2==3){
		cont++;
		}
	}
		
	printf("%d\n",cont);
}
