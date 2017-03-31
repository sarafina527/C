//找到小于n的所有质数，筛法
class Solution {
public:
    int countPrimes(int n) {
    	int ans = 0;
        vector<bool> isPrime(n,true);
        for(int p=2;p*p<n;p++){
        	if(isPrime[p]){
        		for(int k=p*p;k<n;k+=p)//将该质数的倍数排除
        			isPrime[k] = 0;
        	}
        }
        for(int i=2;i<n;i++){
        	if(isPrime[i])
        		ans++;
        }
        return ans;
    }
};