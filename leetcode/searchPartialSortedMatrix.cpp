class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	bool ans = 0;
        int m = matrix.size();
        if(m){
        	int n = matrix[0].size();
        	if(n){
        		int maxrow = m-1,i=m-1,mincol = 0;
        		while(maxrow>=0&&mincol<n){
        			for(i=maxrow;i>=0;i--){
	        			if(matrix[i][mincol]==target){
	        				return 1;
	        			}else if(matrix[i][mincol]<target){
	        				maxrow = i;
	        				break;
	        			}	
	        		}
	        		if(i<0)
	        			return 0;
	        		for(i = 0;i<=mincol;i++){
	        			if(matrix[maxrow][i]==target)
	        				return 1;
	        			else if(matrix[maxrow][i]>target){
	        				mimcol = i;
	        				break;
	        			}
	        		}
	        		if(i==n)
	        			return 0;
        		}
        	}
        }
    }
};