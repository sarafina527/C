class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor) return 0;
        long long a = dividend,b=divisor;
        bool sign = (a>=0&&b>0)||(a<0&&b<0);
        a = a>=0?a:-a;
        b = b>0?b:-b;
        long long ans = 0, shift=0;
        while(a>=b){
            long long tmp = b;
            shift = 0;
            while((tmp<<1)<=a){
                tmp = tmp<<1;
                shift++;
            }
            a -= tmp;
            tmp = 1;
            ans+=(tmp<<shift);
        }
        ans = sign?ans:-ans;
        return ans<=INT_MAX?ans:INT_MAX;        
    }
};