class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> lastindex;
        for(int i=0;i<nums.size();i++){
        	if(lastindex.find(nums[i])==lastindex.end())
        		lastindex[nums[i]] = i;
        	else if(i - lastindex[nums[i]]>k)
        		lastindex[nums[i]] = i;
        	else
        		return true;
        }
        return false;
    }
};