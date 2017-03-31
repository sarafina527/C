class Solution {
public:
    bool isPerfectSquare(int num) {
        long long p=1,q=num;
        while(p<=q){
        	long long mid = (p+q)/2;
        	if(mid*mid==num)
        		return true;
        	else if(mid*mid>num)
        		q = mid-1;
        	else 
        		p = mid+1;
        }
        return false;
    }
};