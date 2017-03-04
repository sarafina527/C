class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int k = nums.size()/2+1;
        buildHeap(nums,k);
        for(int i=k;i<nums.size();i++){
            if(nums[i]<nums[0]){
                int tmp = nums[0];
                nums[0] = nums[i];
                nums[i] = tmp;
                maxHeapify(nums,0,k);
            }
        }
        return nums[0];
        
    }
    void buildHeap(vector<int>& hnums,int k){
        for(int i=k/2;i>=0;i--){
            maxHeapify(hnums,i,k);
        }
    }
    void maxHeapify(vector<int> &a,int i,int heapsize){
        int maxci = i;
        if(left(i)<heapsize&&a[left(i)]>a[i]){//第一个条件判断边界
            maxci = left(i);
        }
        if(right(i)<heapsize&&a[right(i)]>a[maxci]){
            maxci = right(i);
        }
        if(maxci!=i){
            int tmp = a[i];
            a[i] = a[maxci];
            a[maxci] = tmp;
            maxHeapify(a,maxci,heapsize);
        }
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
};