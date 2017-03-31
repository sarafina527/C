class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	long long n = nums.size();
    	long long nsum = (n*(n+1))>>1;
    	long long sum = 0;
    	for(int i=0;i<nums.size();i++)
    		sum += nums[i];
    	int ans = nsum-sum;
    	return ans;
    }
};