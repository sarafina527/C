//73. Set Matrix Zeroes
//tag: Array
//问题描述：将矩阵中0所在的行和列全部清为0，陷阱是如果在遍历过程中就清零，因为有一行和一列全为0，最后矩阵都是0
//特殊要求：空间复杂度O(1)
//思路：1.因为扫第一次时需要记录需要清零的行和列 所以需要O(m+n)空间
//      2.为了降到常数级，可以利用矩阵原来的无用空间，因为扫到第一个零M[i][j]之后，i行和j列的数会被清零，这部分空间（m+n）已经无意义了，可以用作存放某行某列需要清0标记
//      3.将需要清零的标记0
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(!m||!matrix[0].size()) return;
        int n = matrix[0].size();
        pair<int,int> ftzero;
        bool ftflag = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ftflag&&matrix[i][j]==0){
                    ftflag = 0;
                    ftzero = make_pair(i,j);
                }else if(matrix[i][j]==0&&i!=ftzero.first&&j!=ftzero.second){
                    matrix[i][ftzero.second] = 0;
                    matrix[ftzero.first][j] = 0;
                }
            }
        }
        for(int i=0;i<m;i++){
            if(i==ftzero.first) continue;
            for(int j=0;j<n;j++){
                if(j==ftzero.second) continue;
                if(!matrix[i][ftzero.second]||!matrix[ftzero.first][j])
                    matrix[i][j] = 0;
            }
        }
        if(!ftflag){
            for(int i=0;i<m;i++)
                matrix[i][ftzero.second] = 0;
            for(int j=0;j<n;j++)
                matrix[ftzero.first][j] = 0;
        }
    }
};