class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    	int ans = 0;
        int n = nums.size()-1;
        long long p=1,q = n;
        while(p<=q){
        	int mid = (p+q)/2;
        	int smallcount = 0,biggercount = 0;
        	for(int i=0;i<nums.size();i++){
        		if(nums[i]<mid)
        			smallcount++;
        		else if(nums[i]>mid)
        			biggercount++;
        	}
        	if(smallcount+biggercount<n){//equal cur more than 1
    			ans = mid;
    			break;
    		}else if(smallcount>mid-1)//target smaller than cur
    			q = mid-1;
    		else if(biggercount>n-mid)//target bigger than cur
    			p = mid+1;
        }
        return ans;
    }
};