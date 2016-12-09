/*
 *11110
 *11010
 *11000
 *00000
 *起始是求连同分量的个数
 *input：["11110","11010","11000","00000"]
 *水平竖直方向可达[-1,0] [1,0] [0,-1] [0,1] 
 *可以达到的条件是  i>=0&&i<grid.size() j>=0&&j<grid[0].size() grid[i][j]==1 label[i][j]==0
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();//m行
        if(m==0) return 0;
        int n = grid[0].size();//n列
        vector<vector<int> > label(m,vector<int>(n));
        for(int i=0;i<m;i++){
        	for(int j=0;j<n;j++){
        		label[i][j] = 0;
        	}
        }
        int labeln = 0;
        for(int i=0;i<m;i++){
        	for(int j=0;j<n;j++){
        		if(!label[i][j]&&grid[i][j]=='1'){
        			dfs(grid,label,i,j,++labeln);
        		}
        	}
        }
        return labeln;

    }
    void dfs(vector<vector<char>>& grid,vector<vector<int>> &label,int i,int j,int labeln){
       
    	if(i<0||i>=grid.size()||j<0||j>=grid[0].size()) return;
    	if(grid[i][j]!='1'||label[i][j]) return;
// 		cout<<"("<<i<<","<<j<<")"<<" grid="<<grid[i][j]<<" label="<<label[i][j]<<" labeln="<<labeln<<endl;
    	label[i][j] = labeln;
    	dfs(grid,label,i+1,j,labeln);
    	dfs(grid,label,i,j+1,labeln);
    	dfs(grid,label,i-1,j,labeln);    	
    	dfs(grid,label,i,j-1,labeln);  	
    }
};