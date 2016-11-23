#include <stdio.h>

int main(){
	long long n,m;
	int kcase =0;
	long long square;

	while(scanf("%ld%ld",&n,&m)==2&&n&&m){
		double s = 0;
//		for(long long i = n;i<=m;i++){
//			square = i*i;
//			s+=1.0/square;
//		}
		for(int i = n;i<=m;i++){
			square = (long long)i*i;
			s+=1.0/square;
		}
		if(kcase++){
			printf("\n");
		}
		printf("Case %d: %0.5f\n",kcase,s);
	}
	return 0;
}
