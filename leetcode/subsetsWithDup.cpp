class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sofar;
        subsetsWithDup(nums,nums.size()-1,sofar,ans);
        sort(ans.begin(),ans.end(),vecCMP);
        return ans;

    }
    void subsetsWithDup(vector<int>& nums,int p,vector<int> sofar,vector<vector<int>> &ans) {
        if(p<0)
            ans.push_back(sort(sofar.begin(),sofar.end()));
        else{
            if(checkRepeat(nums,p)&&find(sofar.begin(),sofar.end(),nums[p])!=sofar.end()){
               sofar.push_back(nums[p]);
               subsetsWithDup(nums,p-1,sofar,ans);
               
            }else{
                subsetsWithDup(nums,p-1,sofar,ans);
                sofar.push_back(nums[p]);
                subsetsWithDup(nums,p-1,sofar,ans);
            }
            
        }
    }
    bool checkRepeat(vector<int>& nums,int p){
        int key = nums[p];
        for(int i=p+1;i<nums.size();i--){
            if(nums[i]==key)
                return 1;
        }
        return 0;
    }
    bool vecCMP(vector<int> v1,vector<int> v2){
        for(int i=0;i<v1.size()&&i<v2.size();i++){
            if(v1[i]==v2[i])
                continue;
            else
                return v1[i]<v2[i];
        }
        return v1.size()<v2.size();
    }
};