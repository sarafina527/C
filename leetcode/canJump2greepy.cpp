class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJump(nums,0);
    }
    bool canJump(vector<int>& nums,int start){
        if(nums[start]+start>=nums.size()-1)
            return true;
        else{
            int max = nums[start]+start;
            int maxi = start;
            for(int i=start;i<=start+nums[start];i++){
                if(nums[i]+i>max){
                    max = nums[i]+i;
                    maxi = i;
                }
            }
            if(maxi==start) return false;
            else{
                return canJump(nums,maxi);
            }
        }
    }
};