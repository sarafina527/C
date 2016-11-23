#include <stdio.h>
#include <math.h>

int main(){
	int a,b,c,kcase=0;
	while(scanf("%d%d%d",&a,&b,&c)==3&&(a||b||c)){
		double division = (double)a/b;
		int divint = floor(division);
		if(kcase++){
			printf("\n");
		}
		printf("Case %d: %d.",kcase,divint);
		int left = a - b*divint;
		for(int i=0;i<c-1;i++){
			printf("%d",(left*10)/b);
			left= (left*10)%b;
//			printf("%d",left);
		}
		int tail = floor((double)left*10/b+0.5);
		printf("%d\n",tail);	
		
	}
}
