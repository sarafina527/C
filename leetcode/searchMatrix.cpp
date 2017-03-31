class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m){
        	int n = matrix[0].size();
        	if(n){
        		int p = 0;
        		int q = m*n-1;
        		while(p<=q){
        			int mid = (p+q)/2;
	        		if(matrix[mid/n][mid%n]==target)
	        			return true;
	        		else if(matrix[mid/n][mid%n]<target)
	        			p = mid+1;
	        		else
	        			q = mid-1;
        		}
        		
        	}
        }
        return false;
    }
};