class Solution {
public:
    bool isHappy(int n) {
    	map<int,int> book;
        while(n!=1&&book.find(n)==book.end()){
            book[n]++;
        	n = squareSum(n);
        }
        if(n==1) return true;
        else return false;
    }
    int squareSum(int n){
    	int sum = 0;
    	while(n){
    		int tmp = n%10;
    		sum += tmp*tmp;
    		n /= 10;
    	}
    	return sum;
    }
};