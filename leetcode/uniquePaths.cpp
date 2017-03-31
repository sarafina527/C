class Solution {
public:
    int uniquePaths(int m, int n) {
    	int ans = 0;
    	vector<int> tmp(n+1,-1);
    	vector<vector<int>> book(m+1,tmp);
    	if(m>0&&n>0)
        	ans = uniquePaths(m,n,book);
        return ans;
    }
    int uniquePaths(int m,int n,vector<vector<int>> &book){
    	if(m==1||n==1){
        	book[m][n] = 1; 
        }else{
        	int tops = book[m-1][n]!=-1?book[m-1][n]:uniquePaths(m-1,n,book);
        	int lefts = book[m][n-1]!=-1?book[m][n-1]:uniquePaths(m,n-1,book);
        	book[m][n] = tops+lefts;
        }
        return book[m][n];
    }
};