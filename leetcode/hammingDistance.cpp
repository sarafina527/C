class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp = x^y;
        int ans = 0;
        while(tmp){
        	ans++;
        	tmp = tmp&(tmp-1);
        }
        return ans;
    }
};