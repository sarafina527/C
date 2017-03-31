//6. ZigZag Conversion
//tag：String
//问题描述：将字符串按反N字排列，然后按行忽略空格读取字符，返回转化后的串
//思路：申请辅助空间，按照规则 将字符串的字符放到board中，然后再board中按行压入解串
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string ans = string();
        int numCols = (s.size()/(2*numRows-2)+1)*(numRows-1);//计算需要的列
        vector<char> tmp(numCols,'\0');
        vector<vector<char>> board(numRows,tmp);//申请二维数组，按规则存放字符
        int i=0,j=0,si=0;
        bool flag = 1;
        while(si<s.size()){
            if(flag){
                if(i<numRows){
                    board[i++][j] = s[si++];
                }else{
                    flag = 0;
                    i-=2;
                    j++;
                }
            }else{
                if(i>0)
                    board[i--][j++] = s[si++];
                else{
                    flag = 1;
                }
            }
        }
        for(int i=0;i<numRows;i++){//按行读取
            for(int j=0;j<numCols;j++){
                if(board[i][j]!='\0')
                    ans.push_back(board[i][j]);
            }
        }
        return ans;
    }
};