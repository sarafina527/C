class Solution {
public:
    int reverse(int x) {
    	long long ans=0;
        if(x>=0){
        	while(x>0){
        		ans = 10*ans+(long long)x%10;
        		x = x/10;
        	}
        }else{
        	x = -x;
        	while(x>0){
        		ans = 10*ans+x%10;
        		x = x/10;
        	}
        	ans = -ans;
        }
        if(ans>INT_MAX||ans<INT_MIN){
        	ans = 0;
        }
        return ans;
    }
};