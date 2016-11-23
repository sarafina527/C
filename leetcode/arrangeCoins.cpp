class Solution {
public:
	//最需要注意的是可能sum会出界
    int arrangeCoins(int n) {
    	long long sum = 0;
    	int ans = 0;
        for(int i=0;i<=n;i++){
        	sum = sum+i;
        	if(sum>n){
        		ans = i-1;
        		break;
        	}else if(sum==n){
        		ans = i;
        		break;
        	}
        }
        return ans;
    }
};

class Solution {
public:
	//最需要注意的是可能sum会出界2147483647
    int arrangeCoins(int n) {
    	long long sum = 0;
    	int ans = 0;
    	int p = 1,q = n;
    	int k = (p+q)/2;
    	while(1){
    		sum = (long long)k*(k+1)/2;
    		if(sum>n+k+1){
    			q = k-1;
    			k = (p+q)/2;
    		}else if(sum<n){
    			p = k+1;
    			k = (p+q)/2;
    		}else if(sum>=n&&sum<n+k+1){
    			if(sum==n){
    				ans = k;
    			}else{
    				ans = k-1;
    			}    			
    			break;
    		}
    	}    	
        return ans;
    }
};