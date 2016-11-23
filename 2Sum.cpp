#include <iostream>
#include <algorithm>
using namespace std;
void printarr(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
//1.use the merge method and x-a fuzhu shuzu
bool exist2sum(int a[],int n,int x){
	
	qsort(a,n,sizeof(int),compare);
	int *x_a = new int[n];
	for(int i=0;i<n;i++){
		x_a[i] = x-a[n-i-1];
	}
	int i=0,j=0,k=0;
	int *merge = new int[n+n];	
	while(i<n&&j<n){
		if(a[i]<=x_a[j]){
			if(i<1||a[i-1]!=a[i]){
				merge[k++] = a[i];
			}else if(a[i-1]+a[i]==x){
				return 1;
			}
			i++;		
		}else{
			if(j<1||x_a[j-1]!=x_a[j]){
				merge[k++] = x_a[j];
			}else if(x_a[j-1]+x_a[j]==x){
				return 1;
			}
			j++;
		}
	}
	while(i<n){
		if(i<1||a[i-1]!=a[i]){
				merge[k] = a[i];
			}else if(a[i-1]+a[i]==x){
				return 1;
			}
			i++;
	}
	while(j<n){
		if(j<1||x_a[j-1]!=x_a[j]){
			merge[k++] = x_a[j];
		}else if(x_a[j-1]+x_a[j]==x){
			return 1;
		}
		j++; 
	}
	for(i=0;i<k-1;i++){
		if(merge[i]==merge[i+1]){
			return 1;
		}
	}
	return 0;	
}
//2.use two indeces to trace from the front and end of the sorted array
bool exist2sum2(int a[],int n,int x){
	qsort(a,n,sizeof(int),compare);
	int i=0,j=n-1;
	bool ans = 0;
	while(i<j){
		if(a[i]+a[j]==x){
			ans=1;
			break;
		}else if(a[i]+a[j]<x){
			i++;
		}else{
			j--;
		}
	}
	return ans;
}

int main(){
	int a[] = {2,4,6,8,2,9};
	// cout<<exist2sum(a,sizeof(a)/sizeof(int),8);
	cout<<exist2sum2(a,sizeof(a)/sizeof(int),5)<<endl;

}
