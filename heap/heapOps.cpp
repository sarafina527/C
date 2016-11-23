#include <iostream>
#include <vector>
using namespace std;

/*-----------获取父亲或者儿子的索引---------*/
int parent(int childindice){
	return childindice/2;
}
int left(int parentindice){
	return parentindice*2;
}
int right(int parentindice){
	return parentindice*2+1;
}

/*----------保持最大堆的特性--------------
* 假设当前结点i的左右子树已经符合堆的特性。
*/
void maxHeapify(vector<int> &a,int i,int heapsize){
	int maxci = i;
	if(left(i)<=heapsize&&a[left(i)]>a[i]){//第一个条件判断边界
		maxci = left(i);
	}
	if(right(i)<=heapsize&&a[right(i)]>a[maxci]){
		maxci = right(i);
	}
	if(maxci!=i){
		int tmp = a[i];
		a[i] = a[maxci];
		a[maxci] = tmp;
		maxHeapify(a,maxci,heapsize);
	}
}
void iterative_maxHeapify(vector<int> &a,int i,int heapsize){
	while(1){
		int maxci = i;
		if(left(i)<=heapsize&&a[left(i)]>a[i]){//第一个条件判断边界
			maxci = left(i);
		}
		if(right(i)<=heapsize&&a[right(i)]>a[maxci]){
			maxci = right(i);
		}
		if(maxci!=i){
			int tmp = a[i];
			a[i] = a[maxci];
			a[maxci] = tmp;
			i = maxci;//更新节点为替换过的子节点，并让该子树符合特性
		}else{
			break;//当前堆已经符合，则无需向下递归
		}
	}
	
}
/*----------保持最大堆的特性--------------
* 尾递归优化
*/
void buildMaxHeap(vector<int> &a){
	int heapsize = a.size()-1;//0位抛弃
	for(int i=heapsize/2;i>=1;i--){
		maxHeapify(a,i,heapsize);
	}
}
void heap_sort(vector<int> &a){
	int heapsize = a.size()-1;
	for(int i=heapsize;i>=2;i--){//把最后的元素与根交换，然后heapify，将最后元素移出堆
		int tmp = a[1];
		a[1] = a[heapsize];
		a[heapsize] = tmp;
		heapsize--;
		maxHeapify(a,1,heapsize);
	}
}
void printv(vector<int> &a){
	for(int i=1;i<a.size();i++){
		cout<<a[i]<<'\t';
	}
	cout<<endl;
}

int main(){
	vector<int> a = vector<int>();
	a.push_back(0);//占位
	//4,1,3,2,16,9,10,14,8,7
	a.push_back(4);
	a.push_back(1);
	a.push_back(3);
	a.push_back(2);
	a.push_back(16);
	a.push_back(9);
	a.push_back(10);
	a.push_back(14);
	a.push_back(8);
	a.push_back(7);
	buildMaxHeap(a);
	printv(a);
	//堆 16 14 10 8 7 9 3 2 4 1
	a[1] = 5;
	iterative_maxHeapify(a,1,a.size()-1);
	printv(a);
	heap_sort(a);
	printv(a);
	
	return 0;


}
