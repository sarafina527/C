//9. Palindrome Number
//tag:Math
//问题描述：判断一个整数是否为回文。不使用额外的空间。
//注意点：负数，转成串判断会使用辅助空间
//思路：1.先计算有几位数，头后面有几个零
//      2.头尾的数，如果不同则返回false，如果相同则减去头尾并/10，其实就是向内收缩一步，循环对比
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int hten=1,tmp=x,len=1;
        while(tmp/10){
            tmp/=10;
            hten*=10;
            len++;
        }
        while(len>0){
            int tail = x%10;
            int head = x/hten;
            if(tail!=head){
                return false;
            }
            x = (x-head*hten)/10;
            len-=2;
            hten/=100;
        }
        return true;
    }
};