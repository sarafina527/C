//67.Add Binary
//问题描述：给定两个二进制字符串，返回它们的和（也就是二进制字符串）。
//样例：a = "11" b = "1" return "100".
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        string l,s;
        if(a.size()>b.size()){
            l = a;
            s = b;
        }else{
            l = b;
            s = a;
        }
        int i = l.size()-1;
        int j = s.size()-1;
        ans = l;
        int c = 0;
        for(;i>=0&&j>=0;i--,j--){
            int ai = l[i]-'0';
            int bj = s[j]-'0';
            ans[i] = (ai+bj+c)%2+'0';
            c = (ai+bj+c)/2;
        }
        for(;i>=0&&c;i--){
            int ai = l[i]-'0';
            ans[i] = (ai+c)%2+'0';
            c = (ai+c)/2;
        }
        if(c){
            ans.insert(ans.begin(),c%2+'0');
            c/=2;
        }
        return ans;
    }
};