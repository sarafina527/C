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
    	stack<char> lp = stack<char>();//用于压入左括号
        stack<int> digit = stack<int>();//用于存储数字
        stack<string> str = stack<string>();//用于存储括号里的子串

        string tmp = string();

    	for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){//如果是数字
                digit.push(s[i]-'0');//压入数字
                cout<<"digit="<<s[i]<<endl;
                if(tmp.size()!=0){
                    str.push(tmp);
                    tmp.assign("");
                }
            }else if(s[i]=='['){//如果是括号
    			lp.push(i);//压入左括号的位置

    		}else if(isalpha(s[i])){
                tmp.push_back(s[i]);
            }else if(s[i]==']'){
                if(tmp.size()!=0){
                    str.push(tmp);
                    tmp.assign("");
                }
                string inpstr = str.top();
                str.pop();
                cout<<"inner str is "<<inpstr<<endl;
                int times = digit.top();                
                digit.pop();
                cout<<"times="<<times<<endl;
                lp.pop();
                string res = "";
                for(int i=0;i<times;i++){
                    res.append(inpstr);
                }
                cout<<"res="<<res<<endl;
                if(!lp.empty()){//若是内嵌的，则继续拼接
                    string pre = "";
                    if(!str.empty()){
                        pre = str.top();
                        str.pop();
                    }                             
                    pre.append(res);
                    str.push(pre);
                }else{//若是外层则压入结果
                    ans.append(res);
                }
            } 			
    	}
    	
    	return ans;
    }
    string decodeSubstr(string )
};
int main(){
	Solution sl = Solution();
	cout<<sl.decodeString("2[abc]3[cd]ef");
}
