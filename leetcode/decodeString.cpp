#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
/**
*s = "3[a2[c]]", return "accaccacc".
*/
class Solution {
public:
    string decodeString(string s) {
        string ans = string();
        stack<int> digit = stack<int>();//用于存储数字
        stack<string> strstack = stack<string>();//用于存储括号里的子串
        string tmp = string();
        int num = 0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){//如果是数字
                num = num*10+s[i]-'0';
            }else if(s[i]=='['){//如果是括号,开始等待后面字符
                digit.push(num);//压入数字
                strstack.push(tmp);
                tmp = "";//进入下个层次
                num = 0;
            }else if(s[i]==']'){
                int times = digit.top();
                digit.pop();
                string res = "";
                for(int i=0;i<times;i++){
                    res.append(tmp);
                }
                if(!strstack.empty()){//若是内嵌的，则继续拼接，tmp跳到外层
                    string pre = strstack.top();
                    strstack.pop();
                    tmp = pre+res;
                }else{//若是外层则压入结果
                    ans.append(res);
                    tmp = "";
                }
            }else{//其它字符
                tmp.push_back(s[i]);
            }           
        }
        if(!tmp.empty())
            ans.append(tmp);
        return ans;
    }
};
int main(){
	Solution sl = Solution();
	cout<<sl.decodeString("2[abc]3[cd]ef");
}
