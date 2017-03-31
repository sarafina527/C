class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()<=0) return 0;
        vector<vector<int>> book(triangle.begin(),triangle.end());//标记是否已经计算过
        vector<vector<int>> minsum(triangle.begin(),triangle.end());//保存从当前结点到叶节点的最小和
        for(int i=0;i<book.size();i++){
            for(int j=0;j<book[i].size();j++)
                book[i][j] = 0;
        }
        minimumTotal(triangle,0,0,book,minsum);
        return minsum[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle,int i,int j,vector<vector<int>> &book,vector<vector<int>> &minsum){
        if(j<0||j>i) return INT_MAX;
        if(i==triangle.size()-1){//到最后一行
            book[i][j] = 1;
            minsum[i][j] = triangle[i][j];
            return triangle[i][j];
        }else{
            int leftsum=INT_MAX,rightsum=INT_MAX;
            leftsum = book[i+1][j]?minsum[i+1][j]:minimumTotal(triangle,i+1,j,book,minsum);
            if(j+1<=i+1)
                rightsum = book[i+1][j+1]?minsum[i+1][j+1]:minimumTotal(triangle,i+1,j+1,book,minsum);
            book[i][j] = 1;
            minsum[i][j] = leftsum<rightsum?leftsum+triangle[i][j]:rightsum+triangle[i][j];
            return minsum[i][j];
        }
    }
};