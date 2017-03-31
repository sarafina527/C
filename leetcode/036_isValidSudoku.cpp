class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {	
		if(board.size()!=9||board[0].size()!=9)
			return false;	
		for(int i=0;i<9;i++){//check row
			map<char,int> book;
			for(int j=0;j<9;j++){
				if(!isdigit(board[i][j]))
					continue;
				else if(book.find(board[i][j])!=book.end())
					return false;
				else
					book[board[i][j]]++;
			}
		}
		for(int j=0;j<9;j++){//check col
			map<char,int> book;
			for(int i=0;i<9;i++){
				if(!isdigit(board[i][j]))
					continue;
				else if(book.find(board[i][j])!=book.end())
					return false;
				else
					book[board[i][j]]++;
			}
		}
		for(int b=0;b<9;b++){//check block
			map<char,int> book;
			int coloff = (b%3)*3;
			int rowoff = (b/3)*3;
			for(int i=rowoff;i<rowoff+3;i++)
				for(int j=coloff;j<coloff+3;j++){
					if(!isdigit(board[i][j]))
						continue;
					else if(book.find(board[i][j])!=book.end())
						return false;
					else
						book[board[i][j]]++;
				}	
		}
		return true;
    }
};