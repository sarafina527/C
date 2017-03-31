class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size()-1;
        return canJump(nums,target);
    }
    bool canJump(vector<int>& nums,int target){
    	if(target==0)
    		return true;
    	else{
    		for(int i=0;i<target;i++){
	        	if(nums[i]>=target-i){
	        		if(canJump(nums,i))
	        			return true;
	        	}
	        }
	        return false;
    	}
    }
};
//超时