#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	static bool cmp(int a,int b){
    	return a<b;
	}
	static void print(vector<int>& ans){
		 for(int i=0;i<ans.size();i++){
	    	cout<<ans[i]<<" ";
		}
	}
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> ans = set<int>();
        vector<int> ansv = vector<int>();
        sort(nums1.begin(),nums1.end(),cmp);
        sort(nums2.begin(),nums2.end(),cmp);
        int i=0,j=0;
        while(i<nums1.size()&& j<nums2.size()){
        	if(nums1[i]==nums2[j]){
        		ans.insert(nums1[i]);
        		i++;
        		j++;
        	}else if(nums1[i]<nums2[j]){
        		i++;
        	}else{
        		j++;
        	}
        }
        set<int>::iterator pos;
        for(pos = ans.begin();pos!=ans.end();++pos){
            ansv.push_back(*pos);
        }
        return ansv;
    }
   
};
int main(){
	Solution sl = Solution();
    vector<int> n1 = vector<int>();
    vector<int> n2 = vector<int>();
    n1.push_back(1);
    n1.push_back(2);
    n1.push_back(2);
    n1.push_back(1);
    n2.push_back(2);
    n2.push_back(2);
    vector<int> ans = sl.intersect(n1,n2);
    for(int i=0;i<ans.size();i++){
    	cout<<ans[i]<<" ";
	}
    
	
}
