/*
 * O(1)的方法是三步逆转法
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    	k = k%(nums.size());
    	reverse(nums,nums.size()-k,k);
        reverse(nums,0,nums.size()-k);
        reverse(nums,0,nums.size());
    }
    void reverse(vector<int>& nums,int p,int size){
       
    	int q = p+size-1;
    	while(p<q){
    		int tmp = nums[p];
    		nums[p++] = nums[q];
    		nums[q--] = tmp;
    	}
    }
};