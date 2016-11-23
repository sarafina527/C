#include <stdio.h>
#include <time.h>

int main(){
	const int mod = 1000000;
	int n;
	int S=0;
	scanf("%d",&n);
	if(n>25){
		n = 25;
	}
	for(int i=0;i<=n;i++){
		int factor = 1;
		for(int j = 1;j<=i;j++){
			factor = (factor*j)%mod;
		}
		S = (S+factor)%mod;
	}
	printf("%d\n",S );
	printf("time used %0.2f\n",(double)clock()/CLOCKS_PER_SEC);
	return 0;
}