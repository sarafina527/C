class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sofar;
        permuteUnique(sofar,nums,ans);
        return ans;
    }
    void permuteUnique(vector<int> sofar,vector<int> rest,vector<vector<int>> &ans){
    	if(rest.size()==0)
    		ans.push_back(sofar);
    	else{
    		map<int,int> book;
    		for(int i=0;i<rest.size();i++){
    			if(book.find(rest[i])!=book.end())
    				continue;
    			else{
    				book[rest[i]]++;
    				vector<int> next(sofar.begin(),sofar.end());
    				next.push_back(rest[i]);
    				vector<int> remain;
    				for(int j=0;j<rest.size();j++){
    					if(j!=i)
    						remain.push_back(rest[j]);
    				}
    					
    				permuteUnique(next,remain,ans);
    				
    			}
    		}
    	}
    }
};