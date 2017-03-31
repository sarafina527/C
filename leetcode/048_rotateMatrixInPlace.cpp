class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        double mid;
        if(n&1)//odd
        	mid = n>>1;
        else
        	mid = (n>>1)-0.5;
        for(int i=0;i<=mid;i++){
        	for(int j=i;j<n-1-i;j++){
        		int ri = i,rj = j,cur=matrix[i][j];
	        	for(int k = 0;k<4;k++){
	        		double rowoff = ri-mid;
	        		double coloff = rj-mid;
	        		ri = mid+coloff;
	        		rj = mid-rowoff;
	        		int next = matrix[ri][rj];
	        		matrix[ri][rj] = cur;
	        		cur = next;
	        	}
        	}
        	
        }
    }
};
//[[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]
//[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
//[[1,2,3],[4,5,6],[7,8,9]]
//[[1,2],[3,4]]
//[[1]]
//[]