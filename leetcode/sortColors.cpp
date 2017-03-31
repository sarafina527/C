class Solution {
public:
    void sortColors(vector<int>& nums) {
        int reds = 0;
        int blues = nums.size()-1; 
        for(int i=reds;i<=blues;){
        	while(nums[reds]==0&&reds<=blues)
        		reds++;
        	i = reds>i?reds:i;
        	while(nums[blues]==2&&blues>=reds)
        		blues--;	
        	if(nums[i]==0&&reds<=blues){
        		int tmp = nums[i];
        		nums[i] = nums[reds];
        		nums[reds++] = tmp;
        	}else if(nums[i]==2&&blues>=reds){
        		int tmp = nums[i];
        		nums[i] = nums[blues];
        		nums[blues--] = tmp;
        	}else
        	    i++;
        }
    }
};