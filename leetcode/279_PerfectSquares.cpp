//279. Perfect Squares
//tag：BFS，DP，Math
//问题描述：给定正整数n，求出由平方数相加的最少个数
//样例： n = 13, return 2 because 13 = 4 + 9
//思路：1.递归，每次从sqroot平方根到1选择i，left=n-i*i,以left递归下去，二分查找到平方根
//		2.注意dp，保存每个自结果
//		3.注意剪枝，当sofar当前长度大于之前的ans时，直接剪枝，因为最后结果不可能小于ans了
class Solution {
public:
    int numSquares(int n) {
    	map<int,int> book;
    	vector<int> lookup(1,0);
    	for(int i=1;i*i<=n;i++){
    		lookup.push_back(i*i);
    	}
    	return numSquares(n,book,lookup,0,INT_MAX);
    }
    int numSquares(int n,map<int,int> &book,vector<int> &lookup,int sofar,int preans){
    	if(n==0){//base case
    		book[0] = 0;
    		return 0;
    	} 
    	if(sofar>=preans) return INT_MAX;//剪枝
    	if(book.find(n)!=book.end()) return book[n];
    	else{
    		int sqroot = binarySearchSqroot(lookup,n);
	        int ans = INT_MAX;
	        for(int i=sqroot;i>=1;i--){
	        	int left = n-i*i;
	        	int oneopt = numSquares(left,book,lookup,sofar+1,ans);
	        	if(oneopt<ans&&oneopt+1<ans)
	        		ans = oneopt+1;
	        }
	        book[n] = ans; 
	        return ans;
    	}
        
    }
    int binarySearchSqroot(vector<int> &lookup,int n){
    	int p=1,q=lookup.size()-1;
    	while(p<=q){
    		int mid = p+(q-p)/2;
    		if(lookup[mid]<=n&&(mid+1==lookup.size()||lookup[mid+1]>n))
    			return mid;
    		else if(lookup[mid]<n)
    			p = mid+1;
    		else 
    			q = mid-1;
    	}
    }
};