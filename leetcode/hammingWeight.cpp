class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
        	ans++;
        	n = n&(n-1);//clear the lowest 1 everytime
        }
        return ans;
    }
};