#include <iostream>
using namespace std;

void Bubble_Sort(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=1;j<n-i;j++){
			if(a[j-1]>a[j]){
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
}
void Bubble_Sort2(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>i;j--){
			if(a[j-1]>a[j]){
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
}
void printarr(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}


int main(){
	int arr[] = {3,4,2,6,1,5};
	Bubble_Sort2(arr,sizeof(arr)/sizeof(int));
	printarr(arr,sizeof(arr)/sizeof(int));

}
