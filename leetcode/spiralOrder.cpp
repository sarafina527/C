class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> ans;
    	int m = matrix.size(),n=0;
    	if(m==0){
    		return ans;
    	}else if(m==1){
    		return matrix[0];
    	}else
    		n = matrix[0].size();
        vector<bool> tmp(n,0);
        vector<vector<bool>> book(m,tmp);

        for(int i=0,j=0,sofar=0;sofar<m*n;){
        	
			while(j<n&&!book[i][j]){
				book[i][j] = 1;
				ans.push_back(matrix[i][j++]);
				sofar++;
			}
			j--;i++;
			while(i<m&&!book[i][j]){
				book[i][j] = 1;
				ans.push_back(matrix[i++][j]);
				sofar++;
			}
			i--;j--;
			while(j>=0&&!book[i][j]){
				book[i][j] = 1;
				ans.push_back(matrix[i][j--]);
				sofar++;
			}
			j++;i--;
			while(i>=0&&!book[i][j]){
				book[i][j] = 1;
				ans.push_back(matrix[i--][j]);
				sofar++;
			}
			i++;j++;
        }
        return ans;

    }
};