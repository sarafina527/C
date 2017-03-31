class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	int n = board.size(),c=board[0].size();
    	vector<int> tmp(c,0);
    	vector<vector<int>> book(n,tmp)
        for(int i=0;i<board.size();i++){
        	for(int j=0;j<board[i].size();j++){
        		if(board[i][j]==word[0])
        			if(exist(board,word.substr(1),i,j,book))
        				return true;
        	}
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word,int i,int j,vector<vector<int>> &book){
    	if(word.size()==0)
    		return true;
    	else{
    	    bool flag = 0;
    	    book[i][j] = 1;
    		if(i-1>=0&&board[i-1][j]==word[0]&&!book[i-1][j]){
    			flag = exist(board,word.substr(1),i-1,j,book);
    			book[i-1][j] = 0;
    		}
    		if(i+1<board.size()&&board[i+1][j]==word[0]&&!book[i+1][j]){
    			flag = exist(board,word.substr(1),i+1,j,book);
    			book[i+1][j] = 0;
    		}
    		if(j-1>=0&&board[i][j-1]==word[0]&&!book[i][j-1]){
    			flag = exist(board,word.substr(1),i,j-1,book);
    			book[i][j-1] = 0;
    		}
    		if(j+1<board[i].size()&&board[i][j+1]==word[0]&&!book[i][j+1]){
    			flag = exist(board,word.substr(1),i,j+1,book);
    			book[i][j+1] = 0;
    		}
    		return flag;
    	}
    }
};