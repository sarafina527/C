#include <stdio.h>
int main(int argc, char const *argv[])
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	float ave;
	ave = (a+b+c)/3.0;
	printf("%0.3f\n",ave );
	return 0;
}
