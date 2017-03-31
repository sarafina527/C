class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	if(s3.size()!=s1.size()+s2.size())
    		return false;
    	vector<char> tmp(s2.size()+1,-1);
    	vector<vector<char>> book(s1.size()+1,tmp) ;
        return isInterleave(s1,s2,s3,book);
    }
    bool isInterleave(string s1, string s2, string s3,vector<vector<char>> &book){
    	if(s1.size()==0&&s2.size()==0&&s3.size()==0){
    		book[0][0] = 1;
    		return true;
		}else{
			int m = s1.size(),n = s2.size();
			if((n==0||s2[0]!=s3[0])&&s3[0]==s1[0]){
				if(book[m-1][n]==-1)
					book[m-1][n] = isInterleave(s1.substr(1),s2,s3.substr(1));	
				book[m][n] = book[m-1][n];
				return book[m][n];
			}else if((m==0||s1[0]!=s3[0])&&s3[0]==s2[0]){
				if(book[m][n-1]==-1)
					book[m][n-1] = isInterleave(s1,s2.substr(1),s3.substr(1),book);
				book[m][n] = book[m][n-1];
				return book[m][n-1];
			}else if(m>0&&n>0&&s1[0]==s3[0]&&s2[0]==s3[0]){
				if(book[m-1][n]==-1)
					book[m-1][n] = isInterleave(s1.substr(1),s2,s3.substr(1),book);
				if(book[m-1][n]==1){
					book[m][n] = 1;
					return true;
				}
				if(book[m][n-1]==-1)
					book[m][n-1] = isInterleave(s1,s2.substr(1),s3.substr(1),book);
				if(book[m][n-1]==1){
					book[m][n] = 1;
					return true;
				}
			}
			book[m][n] = false;
			return false;
    	}
    }
};