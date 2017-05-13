class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    	int ans=0;
    	map<int,int> turnup;
    	map<pair<int,int>,int> has;
        for(int i=0;i<nums.size();i++){
        	if(turnup.find(nums[i]-k)!=turnup.end()){
        		pair<int,int> tmp = make_pair(nums[i]-k,nums[i]);//有序对
        		if(has.find(tmp)==has.end()){//不在解里面则添加
        			ans++;
        			has[tmp]++;
        		}
        	}
        	if(turnup.find(nums[i]+k)!=turnup.end()){
        		pair<int,int> tmp = make_pair(nums[i]+k,nums[i]);
        		if(has.find(tmp)==has.end()){
        			ans++;
        			has[tmp]++;
        		}
        	}
        }
        return ans;
    }
};