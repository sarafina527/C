class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> ans(rowIndex+1,0);
    	ans[0] = 1;
    	vector<int> col(rowIndex+1,1);
        for(int j=1;j<=rowIndex/2;j++){//第j列的数
        	int leftup = col[j];
        	col[j] = 1;
        	for(int i = j+1;i<=rowIndex;i++){
        		int preserve = col[i];
        		col[i] = col[i-1]+leftup;
        		leftup = preserve;
        	}
        	ans[j] = col[rowIndex];
        }
        int i=0,j=rowIndex;
        while(i<j){
        	ans[j--] = ans[i++];
        }
        return ans;
    }
};