class Solution {
public:
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> ans;
    	for(int i=0;i<numRows;i++){
    		vector<int> tmp(i+1,1);
    		ans.push_back(tmp);
    	}
        for(int i = 1;i<numRows;i++){
        	for(int j=1;j<ans[i].size()-1;j++){
        		ans[i][j] = ans[i-1][j-1]+ans[i-1][j];
        	}
        }
        return ans;
    }
};