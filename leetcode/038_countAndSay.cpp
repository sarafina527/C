class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        	return "11";
        string pre = countAndSay(n-1);
        string ans ;
        for(int i=0;i<pre.size();){
        	int j=i+1;
        	for(;j<pre.size()&&pre[j]==pre[i];j++);
        	ans.push_back(j-i+'0');
        	ans.push_back(pre[i]+'0');
        	i = j;
        }
        return ans;
    }
};