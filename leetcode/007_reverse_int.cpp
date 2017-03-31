//7. Reverse Integer
//tag: Math
//问题描述：整数的反向数字，Example2: x = -123, return -321
//假设：假定为32位有符号整数。当反整数溢出时，函数应返回0。
//思路：先转化成long long 防止反转后溢出，然后ans每次乘10+x%10
class Solution {
public:
    int reverse(int x) {
        long long ans=0;//ans可能溢出，如2147483648 反转后溢出
        if(x>=0){
            while(x>0){
                ans = 10*ans+(long long)x%10;
                x = x/10;
            }
        }else{
            x = -x;
            while(x>0){
                ans = 10*ans+x%10;
                x = x/10;
            }
            ans = -ans;
        }
        if(ans>INT_MAX||ans<INT_MIN){//溢出返回0
            ans = 0;
        }
        return ans;
    }
};