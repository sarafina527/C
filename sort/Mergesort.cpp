#include <iostream>
#include <vector>
#include <climits> 
using namespace std;
//1.use the sentinels
void Merge(int a[],int p,int q,int r){
	vector<int> L = vector<int>();
	vector<int> R = vector<int>();
	for(int i=p;i<=q;i++){
		L.push_back(a[i]);
	}
	L.push_back(INT_MAX);	
	for (int i = q+1; i <= r; ++i)
	{
		R.push_back(a[i]);
	}
	R.push_back(INT_MAX);
	
	int i=0,j=0;
	for(int k=p;k<=r;k++){
		if(L[i]<=R[j]){
			a[k] = L[i++];
		}else{
			a[k] = R[j++];
		}
	}
}
//2.without sentinels ,check the empty array
void Merge2(int a[],int p,int q,int r){
	int n1=	q-p+1,n2=r-q;
	vector<int> L = vector<int>();
	vector<int> R = vector<int>();
	for(int i=p;i<=q;i++){
		L.push_back(a[i]);
	}
	for (int i = q+1; i <= r; ++i)
	{
		R.push_back(a[i]);
	}
	int i=0,j=0;
	for(int k=p;k<=r;k++){
		if(i<n1&&j<n2){
			if(L[i]<=R[j]){
				a[k] = L[i++];
			}else{
				a[k] = R[j++];
			}
		}else if(i<n1){
			a[k] = L[i++];
		}else{
			a[k] = R[j++];
		}
		
	}
}
void Merge_Sort(int a[],int p,int r){
	if(p<r){
		int q = (p+r)/2;
		Merge_Sort(a,p,q);
		Merge_Sort(a,q+1,r);
		Merge2(a,p,q,r);
	}
}
void printarr(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

int main(){
	int arr[] = {2,4,5,7,1,2,3,6};
	Merge_Sort(arr,0,sizeof(arr)/sizeof(int)-1);
	printarr(arr,sizeof(arr)/sizeof(int));
}
