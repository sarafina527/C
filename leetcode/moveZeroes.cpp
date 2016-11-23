class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int zerof = nums.size();
    	for(int i=zerof-1;i>=0;i--){
    		if(nums[i]==0){
    			for(int j=i+1;j<zerof;j++){
    				int t = nums[j-1];
    				nums[j-1] = nums[j];
    				nums[j] = t;
    			}
    			zerof--;
    		}
    	}
        
    }
};