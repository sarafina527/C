//数组的子集
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> ans;
    	vector<int> oneset;
    	subsets(nums,oneset,ans);
    	return ans;
    	
    }
    void subsets(vector<int> nums,vector<int> setpre,vector<vector<int>> &ans){

    	if(nums.size()==0){
    		reverse(setpre);
    		ans.push_back(setpre);
    	}else{
    	    vector<int> newnums;
    		if(nums.size()>=2)
    			newnums=vector<int>(nums.begin(),nums.end()-1);
    		subsets(newnums,setpre,ans);
    		vector<int> newsp = setpre;
	    	newsp.push_back(nums[nums.size()-1]);
	    	subsets(newnums,newsp,ans);
	    	
    	}
    }
    void reverse(vector<int> &nums){
    	for(int i=0,j=nums.size()-1;i<=j;i++,j--){
    		int temp = nums[i];
    		nums[i] = nums[j];
    		nums[j] = temp;
    	}
    }
};