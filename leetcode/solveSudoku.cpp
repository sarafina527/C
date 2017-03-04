class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
    	if(board.size()==0) return;
    	vector<int> listi;
        vector<int> listj;
    	vector<bool> tmp(10,0);
    	vector<vector<bool>> sofari(board.size(),tmp);
    	vector<vector<bool>> sofarj(board.size(),tmp);
        vector<vector<bool>> sofark(board.size(),tmp);
    	for(int i=0;i<board.size();i++){
    		for(int j=0;j<board[0].size();j++){
    			if(board[i][j]=='.'){
    				listi.push_back(i);
    				listj.push_back(j);
    			}else{
                    int d = board[i][j]-'0';
    				sofari[i][d] = 1;
    				sofarj[j][d] = 1;
                    sofark[mapk(i,j)][d] = 1;
    			}
    		}
    	}
    	solveSudoku(board,listi,listj,sofari,sofarj);
    }
    bool solveSudoku(vector<vector<char>>& board,vector<int> &listi,vector<int> &listj,vector<vector<bool>> &sofari,vector<vector<bool>> &sofarj,vector<vector<bool>> &sofark){
    	if(listi.size()==0&&listj.size()==0){
    		return true;
    	}else{
    		int i = listi.back();
    		int j = listj.back();
    		
    		for(int d=1;d<=9;d++){
	    		if(sofari[i][d]==0&&sofarj[j][d]==0&&sofark[mapk(i,j)][d]==0){
	    			board[i][j] =  d+'0';
	    			cout<<board[i][j]<<" ";
	    			sofari[i][d] = 1;
    				sofarj[j][d] = 1;
                    sofark[mapk(i,j)][d] = 1;
    				listi.pop_back();
	    			listj.pop_back();
	    			if(solveSudoku(board,listi,listj,sofari,sofarj,sofark))
	    			    return true;
	    			board[i][j] = '.';
	    			sofari[i][d] = 0;
                    sofarj[j][d] = 0;
                    sofark[mapk(i,j)][d] = 0;
	    			listi.push_back(i);
	    			listj.push_back(j);
	    		}
	    	}
    	}
    	return false;
    	
    }
    int mapk(int i,int j){
        if(i>=0&&i<=2){
            if(j<=2)
                return 0;
            else if(j<=5)
                return 1;
            else
                return 2;
        }else if(i<=5){
            if(j<=2)
                return 3;
            else if(j<=5)
                return 4;
            else
                return 5;
        }esle{
            if(j<=2)
                return 6;
            else if(j<=5)
                return 7;
            else
                return 8;
        }
    }
};