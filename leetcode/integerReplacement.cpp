//dp
//如果N是偶数，用N/2替换N。如果n是奇数，你可以用N+1或N-1代替N。N成为1所需的最小替换数是多少
class Solution {
public:
    int integerReplacement(int n) {
    	unsigned int un = n;
        map<unsigned int,unsigned int> book;
        return intRep(un,book);
    }
    int intRep(unsigned int n,map<unsigned int,unsigned int> &book){
    	if(n==1||n==0){
    		book[1] = 0;
    		return 0;
    	}else{
    		if((n&1)==0){//偶数
    			int halfn = book.find(n/2)!=book.end()?book[n/2]:intRep(n/2,book);
    			book[n] = 1+halfn;
    			return book[n];
    		}else{//奇数
    			int nplus = book.find(n+1)!=book.end()?book[n+1]:intRep(n+1,book);
    			int nminus = book.find(n-1)!=book.end()?book[n-1]:intRep(n-1,book);
    			int ans = nplus<nminus?nplus+1:nminus+1;
    			book[n] = ans;
    			return book[n];
    		}
    	}
    }
};