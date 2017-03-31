class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int sum=0,maxsum = INT_MIN;
    	//一直加，如果加的和小于0，则抛弃之前的和，重新开始
    	for(int i=0;i<nums.size();i++){
    		if(sum<0){
    			sum = 0;
    		}
			sum+=nums[i];
			if(sum>=maxsum){
				maxsum = sum;
			}
    		
    	}
    	return maxsum;
        
    }
};