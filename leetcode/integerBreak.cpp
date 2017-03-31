class Solution {
public:
    int integerBreak(int n) {
    	map<int,int> book;
    	int ans=1;
    	book[1] = 1;
    	book[3] = 2;
    	book[2] = 1;
    	book[4] = 4;
    	if(n<5) return book[n];
    	while(n-3>=2){
    		ans*=3;
    		n-=3;
    	}
    	ans*=n;
        return ans;
    }
};

//dp 超时
class Solution {
public:
    int integerBreak(int n) {
    	map<int,int> book;
    	int ans=1;
    	book[1] = 1;
    	book[3] = 2;
    	book[2] = 1;
    	book[4] = 4;
    	for(n-3>=2){
    		ans*=3;
    		n-=3;
    	}
    	ans*=book[n];
        return ans;
    }
    // int integerBreak(int n,map<int,int> &book){
    // 	if(n==1) return 1;
    // 	int ans = 0;
    // 	for(int i=1;i<=n/2;i++){
    // 		int imp = book.find(i)!=book.end()?book[i]:integerBreak(i);
    // 		if(imp<i)
    // 			imp = i;
    // 		int lmp = book.find(n-i)!=book.end()?book[n-i]:integerBreak(n-i);
    // 		if(lmp<n-i)
    // 			lmp = n-i;
    // 		int product = imp*lmp;
    // 		if(product>ans)
    // 			ans = product;
    // 	}
    // 	book[n] = ans;
    // 	return ans;
    // }

};