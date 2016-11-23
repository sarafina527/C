#include <iostream>
using namespace std;
//1.use the Horner's rule O(n)
//p(x) = a0+x(a1+x(a2+...+s(an-1+xan)...)) n is jie of polynomial
int polynomial(int a[],int n,int x){
	int y=0;
	for(int i=n;i>=0;i--){
		y = a[i]+x*y;
	}
	return y;
}
//2.naive O(n^2)
int naivepolynomial(int a[],int n,int x){
	int y=a[0];
	for(int i=1;i<=n;i++){
		int xx = 1;
		for(int j=0;j<i;j++){
			xx*=x;
		}
		y+=xx;
	}
	return y;

}

int main(){
	int a[] = {1,1,1,1,1};
	cout<<polynomial(a,sizeof(a)/sizeof(int)-1,2)<<endl;
	cout<<naivepolynomial(a,sizeof(a)/sizeof(int)-1,2)<<endl;
}
