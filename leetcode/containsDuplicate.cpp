class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> turnup;
        for(int i=0;i<nums.size();i++){
        	if(turnup.find(nums[i])==turnup.end()){
        		turnup[nums[i]]++;
        	}else
        		return true;
        }
        return false;
    }
};