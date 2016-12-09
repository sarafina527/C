//方法一 超时，朴素，找到重复的数组移位删除
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	
        for(int i=1;i<nums.size();){
        	if(nums[i]==nums[i-1]){//出现重复
        		for(int j=i+1;j<nums.size();j++){//整体左移
        			nums[j-1] = nums[j];
        		}
        		nums.pop_back();
        	}else{
        		i++;
        	}
        }
       
        return nums.size();
    }
};
//two pointer方法，i之前标记是每个出现一次的，i-j之间是需要丢弃的，j之后是未检测的,j遇到新的值交换
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if(nums.size()<=1) return nums.size();
    	int i=0,j=1;
        while(i<nums.size()&&j<nums.size()){
        	if(nums[i]==nums[j]){//出现重复
        		j++;        		
        	}else{
        		nums[++i] = nums[j++];
        	}
        }
        for(int k=i+1;k<nums.size();){
        	nums.pop_back();
        }
        return nums.size();
    }
};