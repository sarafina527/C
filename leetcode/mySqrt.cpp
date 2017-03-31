class Solution {
public:
    int mySqrt(int x) {
    	if(x<0)
    		return MIN_INT;
        long long ans=0;
        square = ans*ans;
        long long square1 = (ans+1)*(ans+1);
        long long p=0,q = x;
        while(!(square<=x&&square1>x)){
        	if(square>x){
        		q = ans;
        	}else if(square<x){
        		p = ans;
        	}
        	ans = (p+q)/2;
        	square = ans*ans;
        	square1 = (ans+1)*(ans+1);
        }
        return ans;
    }
};