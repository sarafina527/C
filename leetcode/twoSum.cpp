class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> ans = vector<int>();
        map<int,int> nindice = map<int,int>();
        for(int i=0;i<nums.size();i++){
        	if(nindice.find(target-nums[i])!=nindice.end()){
        		ans.push(nindice[target-nums[i]],i);
        	}else{
        		nindice[nums[i]] = i;
        	}
        }
    }
};