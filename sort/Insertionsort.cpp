#include <iostream>
using namespace std;

void insertion_sort(int arr[],int n){
	for(int i=1;i<n;i++){
		int j=i-1;
		int key = arr[i];
		while(j>=0&&arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}
void printarr(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}
int main(){
	int arr[] = {5,2,4,6,1,3};
	insertion_sort(arr,sizeof(arr)/sizeof(int));
	printarr(arr,sizeof(arr)/sizeof(int));
}
