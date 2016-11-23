#include <stdio.h>
#include <math.h>

int main(){
	//1.out
	//1.1 placeholder 0.nf
	printf("5/3 = %02d\n",5/3); //int division need to be careful
	printf("5/3.0 = %f\n",5/3.0); 
	printf("8/5.0 = %f\n",8/5.0); //default 6 bit
	printf("8.0/5.0 = %0.2f\n",8.0/5.0); //2 control the 2 bit after .
	//1.2 correct placeholder %
	printf("5/3 = %f\n",5/3);
	printf("5.0/3.0 = %d\n",5.0/3.0); //int float code and store methods are different
	//1.3 math functions need to link the math libary
	float res = sqrt(3);
	printf("sqrt = %f\n",res);


	//2.in
	//2.1 & get the address of var
//	const double pi = acos(-1.0); 
//	float r,h,area;
//	scanf("%f%f",&r,&h);
//	area = (pi*r*r+pi*r*h)*2;
//	printf("%0.3f\n",area);

	//3.type and in format
	int none = 111111;	//n>5 overflow
	printf("none*none = %d\n",none*none );
	float nonef = 111111111;
	printf("nonef*nonef = %f\n",nonef*nonef );
	printf("sqrt(-10) = %f\n", sqrt(-10));
	printf("1.0/0.0 = %f\n", 1.0/0.0);
	printf("0.0/0.0 = %f\n", 0.0/0.0);
//	printf("0/0 = %d\n", 0/0);  //error terminate 
	
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d %d\n",a,b );

	return 0;
} 
