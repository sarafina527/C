class Solution {
public:
    int trailingZeroes(int n) {
    	int ans = 0;
    	if(n==0) return ans;
    	else{
    	    if(n<0){
        		if(n==INT_MIN)
        			n = -(++n);
        		else
        			n = -n;
        	}
    	    for(int i=5;i<=n;i+=5){
    	    	int j = i;
    	    	while(j%5==0){
    	    		ans++;
    	    		j/=5;
    	    	}
            }
    	}
        return n>0?ans:-ans;
    }
};
n为负数
class Solution {
public:
    int trailingZeroes(int n) {
    	int ans = 0;
    	while(n){
    		ans+=n/5;
    		n /=5;
    	}
    	return ans;
    }
};
