//26进制
class Solution {
public:
    int titleToNumber(string s) {
    	int ans = 0;
        map<char,int> lookup;
        int i = 1;
        for(char c='A';c<='Z';c++,i++){
        	lookup[c] = i;
        }
        for(i=0;i<s.size();i++){
        	ans = 26*ans+lookup[s[i]];
        }
        return ans;
    }
};