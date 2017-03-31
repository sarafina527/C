class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

    	vector<int> tmp(n,0);
    	vector<vector<int>> ans(n,tmp);
    	long long square = (long long)n*n;
    	return ans;
        for(int num=1,i=0,j=0;num<=square;){
        	while(j<n&&!ans[i][j]){
        		ans[i][j++] = num++;
        	}
        	i++;j--;
        	while(i<n&&!ans[i][j]){
        		ans[i++][j] = num++;
        	}
        	i--;j--;
        	while(j>=0&&!ans[i][j]){
        		ans[i][j--] = num++;
        	}
        	i--;j++;
        	while(i>=0&&!ans[i][j]){
        		ans[i--][j] = num++;
        	}
        	i++;j++;
        }
        return ans;
    }
};