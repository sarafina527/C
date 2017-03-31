// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long p=1,q=n,mid;
        while(p<=q){
        	mid = (p+q)/2;
        	if(guess(mid)==0)
        		return mid;
        	else if(guess(mid)<0)
        		q = mid-1;
        	else 
        		p = mid+1;
        }
        return mid;
    }
};