/*
 *allowed at most twice sorted array
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;//两个游标，i之前的表示已经检测过不超过两个存在的，i-j之间是重复的数
        while(i<nums.size()&&j<nums.size()){
        	if(nums[j]==nums[i]){
        		if(j-i<2)
        			j++;
        		else{//删除重复多于两次的，j应该不变，重新检测
        			for(int k=j;k<nums.size()-1;k++){
	        			nums[k] = nums[k+1];
	        		}
	        		nums.pop_back();
        		}
        	}else{
        		i=j;
        		j++;
        	}
        }
        return nums.size();
    }
};