//415. Add Strings
//问题描述：给定两个非负整数num1和num2表示为字符串，返回num1和num2的总和。
//假设：两num1和num2长度＜5100。两num1和num2只包含数字0-9。两num1和num2不包含任何前导零
//思路：将两个串逆序，然后按位相加、进位，然后进行与较长的进行加进位，最后看进位是否为0，若不为0继续加到高位，最后忽略前导0，逆序
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans(5101,0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        int c = 0,i=0;
        for(;i<num1.size()&&i<num2.size();i++){
            int cur = (num1[i]-'0')+(num2[i]-'0')+c;
            c = cur/10;
            ans[i] = cur%10+'0';
        }
        if(num1.size()>num2.size()){
            for(;i<num1.size();i++){
                int cur = (num1[i]-'0')+c;
                c = cur/10;
                ans[i] = cur%10+'0';
            }
        }else if(num1.size()<num2.size()){
            for(;i<num2.size();i++){
                int cur = (num2[i]-'0')+c;
                c = cur/10;
                ans[i] = cur%10+'0';
            }
        }
        if(c)
            ans[i] = c+'0';
        
        for(int i=ans.size()-1;i>0&&ans[i]==0;i--){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};