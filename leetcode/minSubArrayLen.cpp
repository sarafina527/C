class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        int sum = 0,size=0,minsize=n+1;
        while(i<n&&j<=n){//为了保证最后一个计算入sum
        	if(sum>=s){
        		size = j-i;
        		if(size<minsize){
        			minsize = size;
        		}
        		sum-=nums[i++];
        	}else if(sum<s){
        		if(j<n)
        			sum+=nums[j++];
        		else
        			break;
        	}      	
        }
        return minsize==n+1?0:minsize;
    }
};