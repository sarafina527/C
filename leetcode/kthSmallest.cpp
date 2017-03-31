class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    	int ans = 0;
        int m = matrix.size();
        if(m){
        	int n = matrix[0].size();
        	if(n){
        		int p = 0;
        		int q = m*n-1;
        		ans = kthSmallest(matrix,k,p,q);
        	}
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k,int p,int q){
    	int mid = (p+q)/2;
    	int m = matrix.size();
    	int n = matrix[0].size();
    	int i = mid/n;
    	if(mid==k-1)
    		return matrix[][mid%n];
    	else if(mid<k-1)
    		return kthSmallest(matrix,k,mid+1,q);
    	else if(mid>k-1)
    		return kthSmallest(matrix,k,p,mid-1);
    }
};