//324. Wiggle Sort II
//tag：sort，heap
//问题描述：给未排序数组排序，使得下标为奇数的元素比两边的元素大
//要求：O（N）的时间和O（1）额外空间或者inplace
//思路：分析：把升序数组的后半部分放入小标为奇数的位置
//		1.借助堆操作，最大堆将数组最小的保持在前半部分
//		2.然后将奇数小标的与后半部分的偶数下标互换
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    	int n=nums.size(), k = n/2.0+0.5;//当是奇数时求上界
        buildMaxHeap(nums,k);
        printHeap(nums,k);
        for(int i=k+1;i<n;i++){
        	if(nums[i]<nums[0]){
        		Swap(&nums[0],&nums[i]);
        		maxHeapify(nums,0,k);
        	}
        }
        printHeap(nums,k);
        int i = 1,j=((n-1)&1)==0?n-1:n-2; //i指向前半段的奇数小标，j是后半部分偶数下标
        while(i<j){
        	Swap(&nums[i],&nums[j]);
        	i +=2;
        	j -=2;
        }
    }
    void buildMaxHeap(vector<int> &a,const int& heapsize){//构建最小堆
		for(int i=heapsize/2;i>=0;i--){//从内节点开始调整堆序，因为叶节点肯定符合堆序属性
			maxHeapify(a,i,heapsize);
		}
	}
	void maxHeapify(vector<int> &a,int i,const int& heapsize){//下沉
		int maxi = i;
		if(left(i)<heapsize&&a[left(i)]>a[maxi])//第一个条件判断边界 找到左右孩子比它小最多的交换
			maxi = left(i);
		if(right(i)<heapsize&&a[right(i)]>a[maxi])
			maxi = right(i);
		if(maxi!=i){//最后叶子的时候会相等||已经符合堆序属性（即比左右孩子都小了）
			Swap(&a[i],&a[maxi]);
			maxHeapify(a,maxi,heapsize);//递归到交换的孩子
		}
	}
	void Swap(int *p,int *q){
		int tmp = *p;
		*p = *q;
		*q = tmp;
	}
	int parent(int childindice){
		return (childindice-1)/2;
	}
	int left(int parentindice){
		return parentindice*2+1;
	}
	int right(int parentindice){
		return parentindice*2+2;
	}
	void printHeap(vector<int>&a,int heapsize){
		for(int i=0;i<heapsize;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
};