#include <iostream>
using namespace std;

int max(int arr[],int len){
	int maxid = 0;
	for(int i=0;i<len;i++){
		if(arr[i]>arr[maxid]){
			maxid = i;
		}
	}
	return maxid;//单一出口原则
}
void swap(int a[],int i,int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}


int main(){
	int a[] = {2,45,79,66,14,41,36,4,55,81};
	int len = sizeof(a)/sizeof(int);
	
	for(int i=0;i<len-1;i++){ 
		int maxid = max(a,len-i);
		swap(a,maxid,len-i);
	}
	//swap maxid and len-1
	for(int i=0;i<len;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
