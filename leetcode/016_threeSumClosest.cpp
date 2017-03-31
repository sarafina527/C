class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int mindiff = INT_MAX,ans=0;
        for(int i=0;i<nums.size()-2;i++)
        	for(int j=i+1;j<nums.size()-1;j++){
        		int p=j+1,q = nums.size()-1;
        		int sofar = nums[i]+nums[j];
        		while(p<=q){
        			int mid = (p+q)/2;
        			int sum = sofar+nums[mid];
        			if(sum==target){
        				return target;
        			}else if(sum>target){
        				if(sum - target<mindiff){
        					mindiff = sum - target;
        					ans = sum;
        				}
        				q = mid-1;
        			}else{
        				if(target - sum<mindiff){
        					mindiff = target - sum;
        					ans = sum;
        				}
        				p = mid+1;
        			}
        		}
        	}
        return ans;
    }
};