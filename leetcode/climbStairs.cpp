class Solution {
public:
    int climbStairs(int n) {
    	int ans = 0;
    	if(n>0){
    		vector<int> book(n+1,0);
    		ans = climbStairs(n,book); 
    	}
    	return ans;    	
    }
    int climbStairs(int n,vector<int>& book) {
        if(n==1)
        	book[n] = 1;      	
        else if(n==2)
        	book[n] = 2;
        else{
        	int n1 = book[n-1]!=0?book[n-1]:climbStairs(n-1,book);
        	int n2 = book[n-2]!=0?book[n-2]:climbStairs(n-2,book);
        	book[n] = n1+n2;
        }
        return book[n];        	
    }
};