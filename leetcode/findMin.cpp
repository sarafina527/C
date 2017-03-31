class Solution {
public:
    int findMin(vector<int>& nums) {
        int p=0,q=nums.size()-1,mid=(p+q)/2;
        while(p<=q){
        	mid = (p+q)/2;
        	if(mid>0&&nums[mid-1]>nums[mid])
        		break;
        	else if(nums[mid]>=nums[0]){
        		p = mid+1;
        	}else
        		q = mid-1;
        }
        return nums[mid]<nums[0]?nums[mid]:nums[0];
    }
};