class Solution {
public:
	void minHeapify(vector<int> &a,int i,int heapsize){
		int maxci = i;
		if(left(i)<heapsize&&a[left(i)]<a[i]){//第一个条件判断边界
			maxci = left(i);
		}
		if(right(i)<heapsize&&a[right(i)]<a[maxci]){
			maxci = right(i);
		}
		if(maxci!=i){
			int tmp = a[i];
			a[i] = a[maxci];
			a[maxci] = tmp;
			minHeapify(a,maxci,heapsize);
		}
	}
	void buildMinHeap(vector<int> &a,int heapsize){
		for(int i=heapsize/2;i>=0;i--){
			minHeapify(a,i,heapsize);
		}
	}
    int findKthLargest(vector<int>& nums, int k) {
        //以K作为heapsize
    	buildMinHeap(nums,k);
    	for(int i=k;i<nums.size();i++){
    		if(nums[i]>nums[0]){
    			int tmp = nums[0];
    			nums[0] = nums[i];
    			nums[i] = tmp;
    			minHeapify(nums,0,k);
    		}
    	}
    	return nums[0];
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
};