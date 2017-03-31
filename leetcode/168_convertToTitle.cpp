//问题描述：将excel表格的整数列号转化为列标题 如27-》AA
//思路：26进制数一样，然后reverse
class Solution {
public:
    string convertToTitle(int n) {
    	string ans;
    	int num = n-1;
        while(n>0){
        	char c = (n-1)%26 +'A';
        	ans.push_back(c);
        	n = (n-1)/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};