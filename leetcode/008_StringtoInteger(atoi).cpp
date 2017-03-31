//8. String to Integer (atoi)
//tag: String,Math
//问题描述：实现atoi将字符串转换为整数。
//思路：1.函数首先丢弃许多空白字符必要直到找到第一个非空白字符。
//      2.考虑负数，这个字符开始（可能是leading加号或减号），后面跟着尽可能多的数值digit
//      3.考虑溢出
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        bool flag = 1;//postive
        long long ans = 0;
        while(i<str.size()&&str[i]==' '){//忽略空白字符
            i++;
        }
        if(i<str.size()&&str[i]=='-'){
            flag = 0;
            i++;
        }else if(i<str.size()&&str[i]=='+'){
            i++;
        }
        while(i<str.size()&&str[i]>='0'&&str[i]<='9'){
            ans = ans*10+(long long)(str[i]-'0');
            cout<<ans<<endl;
            if(flag&&ans>INT_MAX){
                return INT_MAX;
            }else if(!flag&&ans>(long long)INT_MAX+1){
                return INT_MIN;
            }
            i++;
        }
        if(!flag){
            ans = -ans;
        }
        return ans;
    }
};
//strLib 借助istringstream实现
int stringToInteger(const std::string& str, int radix) {
    if (radix <= 0) {//基数
        error("stringToInteger: Illegal radix: " + integerToString(radix));
    }
    std::istringstream stream(trim(str));
    stream >> std::setbase(radix);
    int value;
    stream >> value;
    if (stream.fail() || !stream.eof()) {
        error("stringToInteger: Illegal integer format: \"" + str + "\"");
    }
    return value;
}