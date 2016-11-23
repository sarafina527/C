#include <stdio.h>
#include <limits.h>
#include <math.h>
int main(){
	printf("INT_MIN = %d\n",INT_MIN );
	printf("INT_MAX = %d\n",INT_MAX );
	int n2 = (int)pow(2,31);
	printf("%d\n",n2);

	double dmax  = 1/3.0;
	printf("%0.17lf\n",dmax );
	dmax  = pow(2,53);
	printf("%0.0lf\n",dmax );
	dmax  = pow(2,54);
	printf("%0.0lf\n",dmax );
	dmax  = pow(2,55);
	printf("%0.0lf\n",dmax );
	dmax  = pow(2,56);
	printf("%0.0lf\n",dmax );
	dmax  = pow(2,57);
	printf("%0.0lf\n",dmax );
}
