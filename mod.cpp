#include <stdio.h>
#include <time.h>
int main(){
	int a,b,c;
	int mod;
	scanf("%d%d%d%d",&a,&b,&c,&mod);
	int ans1 = (a*b+c)%mod;
	int ans2 = ((a%mod)*(b%mod)+c%mod)%mod;
	printf("ans1 = %d ans2 = %d\n",ans1,ans2);
	printf("time used %0.2f\n",(double)clock()/CLOCKS_PER_SEC);

}
