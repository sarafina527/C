#include <iostream>
using namespace std;
int min(int a,int b){
	if(a>b){
		return b;
	}else{
		return a;
	}
}
int add(int a[],int b[],int an,int bn,int c[]){
	int n = min(an,bn);
	int flag = 0;
	int i=0;
	for(i=0;i<n;i++){
		c[i] = (a[i]+b[i]+flag)%10;
		flag = (a[i]+b[i]+flag)/10;
	}
	while(i<an||i<bn){
		if(n==an){
			c[i] = (b[i]+flag)%10;
			flag = (b[i]+flag)/10;
		}else{
			c[i] = (a[i]+flag)%10;
			flag = (a[i]+flag)/10;
		}
		i++;
	}
	if(flag>0){
		c[i] = flag;
	}
	return i+1;
	
}
void printarr(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}
int main(){
	int a[] = {1,2,9};
	int b[] = {2,3,4};
	int c[50] = {0};
	int len = add(a,b,sizeof(a)/sizeof(int),sizeof(b)/sizeof(int),c);
	printarr(c,len);
}
