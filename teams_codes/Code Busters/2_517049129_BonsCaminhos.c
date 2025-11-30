#include <stdio.h>

int main(){
	
	long int n,m;
	int cont = 0;
	scanf("%ld %ld",&n,&m);
	
	for(long int i=1; i<=m; i++){
		long int x,y;
		scanf("%ld %ld",&x,&y);
		if(y==n){
			printf("%d\n",cont);
			break;
		}
		else if(y-x==1){
			cont++;
		}
		else{printf("MAUS CAMINHOS!\n");}
		
	}

	return 0;
}

