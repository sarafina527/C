//81. Search in Rotated Sorted Array II
//tag ：binary search
//问题描述：在有重复的已经旋转后的数组中进行二分查找
//思路：先找到旋转的原数组最小值，然后将数组分两段二分查找
//		2.在找数组最小值是也应用二分，每次保持nums[p]>=nums[q],保证范围涵盖最小值的前后，横跨两段数组
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int pivot = findMin(nums);
        //cout<<pivot<<" "<<nums[pivot]<<endl;
        return binarySearch(nums,0,pivot-1,target)||binarySearch(nums,pivot,nums.size()-1,target);
    }
    int findMin(vector<int>& nums){//二分查找最小元素下标
    	int ans=0;
    	int p=0,q=nums.size()-1;
    	while(p<=q&&nums[p]>=nums[q]){
    		if(p+1==q){
    			ans = q;
    			break;
    		}
    		int mid = p+(q-p)/2;
    		if(nums[p]==nums[mid]&&nums[p]==nums[q]){//当三点是重复元素时，不能
    			ans = findMinInorder(nums,p,q);
    			break;
    		}else if(nums[mid]>=nums[p])
    			p = mid;
    		else if(nums[mid]<=nums[q])
    			q = mid;
    	}
    	
    	return ans;
    }
    int findMinInorder(vector<int>& nums,int p,int q){//顺序取最小元素下标
    	int mini = p;
    	for(int i=p+1;i<=q;i++){
    		if(nums[i]<nums[i-1])
    			mini = i;
    	}
    	return mini;
    }
    bool binarySearch(vector<int>& nums,int p,int q,int &target){
    	if(p>=0&&q<nums.size()){
    		while(p<=q){
	    		int mid = p+(q-p)/2;
	    		if(nums[mid]==target)
	    			return true;
	    		else if(nums[mid]<target)
	    			p = mid+1;
	    		else
	    			q = mid-1;
	    	}
    	}
    	return false;
    }
};