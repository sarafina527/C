//tag: greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
    	canJump(nums,0,count);
    	return count;
    }
    void canJump(vector<int>& nums,int start,int& count){
        if(start==nums.size()-1)
            return;
        else if(nums[start]+start>=nums.size()-1)
            count++;
        else{
            int max = nums[start]+start;
            int maxi = start;
            for(int i=start;i<=start+nums[start];i++){
                if(nums[i]+i>max){
                    max = nums[i]+i;
                    maxi = i;
                }
            }
            count++;
            return canJump(nums,maxi,count);
            
        }
    }
};