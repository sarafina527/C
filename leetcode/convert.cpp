class Solution {
public:
    string convert(string s, int numRows) {
    	if(numRows==1) return s;
    	string ans;
    	int c = ((s.size()/(2*numRows-2))+1)*(numRows-1);
    	vector<char> tmp(c,'.');
        vector<vector<char>> board(numRows,tmp);
        int i=0,j=0,si=0;
        bool vflag = 1;
        while(si<s.size()){
        	if(i<numRows&&vflag){
        		board[i++][j] = s[si++];
        	}else if(i<numRows-1&&!flag){
        		board[i++][j++] = s[si++];
        	}else if(vflag){
        		vflag = 0;
        		i =1;
        		j++;
        	}else{
        		vflag = 1;
        		i=0;
        		j++;
        	}
        }
        for (int i = 0; i < board.size(); ++i)
        {
        	for(int j=0;j<board[i].size();j++){
        		if(board[i][j]!='.')
        			ans.push_back(board[i][j]);
        	}
        }
        return ans;
    }
};