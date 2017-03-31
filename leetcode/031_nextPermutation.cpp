class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        int mini = i;
        for(;i>0&&nums[i]<=nums[i-1];i--);//find the target
        if(i>0){
        	int j = i,retarget = nums[i-1];
	    	for(;j<nums.size()-1&&nums[j-1]>=retarget;j++);//find the min one who bigger than target
        	int tmp = nums[i-1];
        	nums[i-1] = nums[j];
        	nums[j] = tmp;
        }
        sort(nums.begin()+i,nums.end());
    }
};