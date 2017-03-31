class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int p=0,q=nums.size()-1;
        while(p<=q){
        	int mid = (p+q)/2;
        	if((mid==0||nums[mid]>nums[mid-1])&&(mid==nums.size()-1||nums[mid]>nums[mid+1]))
        		return mid;
        	else if(mid==0||nums[mid]>nums[mid-1])
        		p = mid+1;
        	else
        		q = mid-1;
        }
        return -1;
    }
};