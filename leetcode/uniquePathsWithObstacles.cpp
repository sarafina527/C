class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	int ans = 0;
    	int m = obstacleGrid.size();
    	if(m){
    		int n = obstacleGrid[0].size();
    		if(n){
    			vector<int> tmp(n,-1);
    			vector<vector<int>> book(m,tmp);
    			ans = uniquePaths(obstacleGrid,m-1,n-1,book);
    		}
    	}
        return ans;
    }
    int uniquePaths(vector<vector<int>>& obstacleGrid,int m,int n,vector<vector<int>> &book){
    	if(obstacleGrid[m][n])
    		book[m][n] = 0;
    	else if(m==0&&n==0){
    		book[m][n] = !obstacleGrid[m][n]; 
        }else if(m==0){
        	book[m][n] = book[m][n-1]!=-1?book[m][n-1]:uniquePaths(obstacleGrid,m,n-1,book);
        }else if(n==0){
        	book[m][n] = book[m-1][n]!=-1?book[m-1][n]:uniquePaths(obstacleGrid,m-1,n,book);        	
        }else{
    		int tops = book[m-1][n]!=-1?book[m-1][n]:uniquePaths(obstacleGrid,m-1,n,book);
    		int lefts = book[m][n-1]!=-1?book[m][n-1]:uniquePaths(obstacleGrid,m,n-1,book);
    		book[m][n] = tops+lefts;
        }
        return book[m][n];
    }
};