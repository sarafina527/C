#include <stdio.h>

int main(){
	long long n;

	while(scanf("%ld",&n)==1&&n){
		double s = 1.0/n;
		printf("%lf\n",s);
	}
	return 0;
}
