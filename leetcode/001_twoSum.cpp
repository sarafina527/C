//1.two sum
//tag array hashtable
//问题描述：给定数组，找到两个元素和是target的下标，
//假设：仅有一个解
//思路：空间换时间，扫一遍one pass，扫的过程中反向映射，在nums[i]时，检查target-nums[i]是否出现过
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int,int> nindice;//反向映射，元素到索引
        for(int i=0;i<nums.size();i++){
            if(nindice.find(target-nums[i])!=nindice.end()){
                ans.push_back(nindice[target-nums[i]]);
                ans.push_back(i);
            }else{
                nindice[nums[i]] = i;
            }
        }
        return ans;
    }
};