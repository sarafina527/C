#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > ans;
    map<int,int> book;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++)
    	book[nums[i]] = i;
    int n = nums.size();
    for(int i=0;i<=n-3;i++){
    	while(i>0&&nums[i]==nums[i-1])
    		i++;
    	for(int j = i+1;j<n-1;j++){
    		while(j>i+1&&nums[j]==nums[j-1])
    			j++;
    		int left = -(nums[i]+nums[j]);
    		if(book.find(left)!=book.end()&&book[left]>i&&book[left]>j){
    			vector<int> tmp;
    			tmp.push_back(nums[i]);
    			tmp.push_back(nums[j]);
    			tmp.push_back(-(nums[i]+nums[j]));
    			ans.push_back(tmp);
    		}
    	}
    }
    return ans;
}
int main(){
	vector<int> nums;
	threeSum(nums);
}

