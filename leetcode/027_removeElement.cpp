//tag： two pointer
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=nums.size();//i扫描，j之后是等于val的,j标记不等于val的
        while(i<j){
        	if(nums[i]==val){
        		int tmp = nums[i];
        		nums[i] = nums[--j];//可能调换的j也是val，所以当前标不变
        		nums[j] = tmp;		
        	}else{
        		i++;
        	}
        	for(int k = j;k<nums.size();k++){
        		nums.pop_back();
        	}	
        }
        return nums.size();
    }
};