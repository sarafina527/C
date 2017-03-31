class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> prefix;
        vector<vector<int>> ans;

        permutation(nums,prefix,ans);
        return ans;

    }
    void permutation(vector<int> nums,vector<int> prefix,vector<vector<int>> &ans){
        if(nums.size()==0){
            ans.push_back(prefix);
        }else{
            for(int i=0;i<nums.size();i++){
                vector<int> newpre(prefix);
                newpre.push_back(nums[i]);
                vector<int> newnums(nums);
                newnums.erase(newnums.begin()+i);
                permutation(newnums,newpre,ans);
                
            }
        }
        
    }
};