//binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	int p=0,q=nums.size(),ans;
    	
    	while(p<=q){
    		ans = (p+q)/2;
    		cout<<ans<<endl;
    		if(nums[ans]>=target){
    			if(nums[ans-1]<target)
	        		break;
	        	else{
	        		q=ans-1;
	        	}
	        }
	        if(nums[ans]<target){
	        	p = ans+1;
	        }
    	}
    	return ans;
        
    }
};