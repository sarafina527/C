class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        vector<int> ones(sizeof(int)*8,0);//用于存储数组中所有数每一位的1的个数
        vector<int> zeros(sizeof(int)*8,0);//用于存储每一位的0的个数
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<sizeof(int)*8;j++){
                if((nums[i]>>j)&1)
                    ones[j]++;
                else
                    zeros[j]++;
            }
        }
        for(int j=0;j<sizeof(int)*8;j++){
            ans += ones[j]*zeros[j];
        }
        return ans;
    }
};