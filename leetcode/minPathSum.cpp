class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    	int ans = 0;
        int m = grid.size(),n=0;
        if(m){
        	n = grid[0].size();
        	if(n){
        		vector<int> tmp(n,-1);
        		vector<vector<int>> book(m,tmp);
        		ans = minPathSum(grid,m-1,n-1,book);
        	}	
        }
        return ans; 
    }
    int minPathSum(vector<vector<int>>& grid,int p,int q,vector<vector<int>>& book){
    	if(p==0&&q==0){
    		book[p][q] = grid[p][q];
    	}else if(p==0){
    		int min = book[p][q-1]!=-1?book[p-1][q]:minPathSum(grid,p,q-1,book);
    		book[p][q] = grid[p][q]+min;
    	}else if(q==0){
    		int min = book[p-1][q]!=-1?book[p-1][q]:minPathSum(grid,p-1,q,book);
    		book[p][q] = grid[p][q]+min;
    	}else{
    		int min = book[p-1][q]!=-1?book[p-1][q]:minPathSum(grid,p-1,q,book);
    		int min2 = book[p][q-1]!=-1?book[p][q-1]:minPathSum(grid,p,q-1,book);
    		if(min2<min)
    			min = min2;
    		book[p][q] = min+grid[p][q];
    	}
    	return book[p][q];
    }
};