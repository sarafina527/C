class Solution {
public:
    int searchRotated(vector<int>& nums, int target) {
    	int n=nums.size(),p=0,q=n-1,start=0;
    	while(p<=q){
    		int mid = (p+q)/2;
    		if(mid>0&&nums[mid]<nums[mid-1]){
    		    start = mid;
    		    break;	
    		}else if(nums[mid]>=nums[0])
    			p = mid+1;
    		else if(nums[mid]<nums[0])
    			q = mid-1;
    	}
        p = 0,q=start-1;
        while(p<=q){
        	int mid = (p+q)/2;
        	if(nums[mid]<target)
        		p = mid+1;
        	else if(nums[mid]>target)
        		q = mid-1;        		
        	else
        		return mid;
        }
        p = start,q=n-1;
        while(p<=q){
        	int mid = (p+q)/2;
        	if(nums[mid]<target)
        		p = mid+1;
        	else if(nums[mid]>target)
        		q = mid-1;        		
        	else
        		return mid;
        }
        return -1;
    }
};