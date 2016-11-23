#include <iostream>
#include <vector>
using namespace std;

int partition(int arr[],int p,int q){
	int x = arr[p];
	int i = p;
	for (int j = p+1; j <= q; ++j)
	{
		if(arr[j]<=x){
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	arr[p] = arr[i];
	arr[i] = x;
	return i;
}

void quicksort(int arr[],int p,int q){
	if(p<q){
		int piv = partition(arr,p,q);
		quicksort(arr,p,piv-1);
		quicksort(arr,piv+1,q);
	}
}
int partition2(int arr[],int p,int q){
	int x = arr[p];
	int i = p+1,j = q;
	while(i<j){
		while(arr[i]<=x){
			i++;
		}
		while(arr[j]>x){
			j--;
		}
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	arr[p] = arr[j];
	arr[j] = x;
}
void quicksort2(int arr[],int p,int q){
	if(p<q){
		int piv = partition2(arr,p,q);
		quicksort(arr,p,piv-1);
		quicksort(arr,piv+1,q);
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = {6,10,13,5,8,3,2,11};
	// quicksort(arr,0,7);
	quicksort2(arr,0,7);
	for (int i = 0; i < 8; ++i)
	{
		cout<<arr[i]<<"\t";
	}
	return 0;
}
