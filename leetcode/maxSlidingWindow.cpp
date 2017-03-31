class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> heap(k,0);
        for(int i=0;i<heap.size();i++)
        	heap[i] = i;
        bulidMaxHeap(heap);


    }
    
	void maxHeapify(vector<int> &a,int i,const vector<int>& nums){
		int maxci = i;
		if(left(i)<=heapsize&&nums[a[left(i)]]>nums[a[i]]){//第一个条件判断边界
			maxci = left(i);
		}
		if(right(i)<=heapsize&&nums[a[right(i)]]>nums[a[maxci]]){
			maxci = right(i);
		}
		if(maxci!=i){
			int tmp = a[i];
			a[i] = a[maxci];
			a[maxci] = tmp;
			maxHeapify(a,maxci,heapsize);
		}
	}
	void buildMaxHeap(vector<int> &a){
		int heapsize = a.size();//0位抛弃
		for(int i=heapsize/2;i>=1;i--){
			maxHeapify(a,i,heapsize,nums);
		}
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