class Solution {
public:
    double myPow(double x, int n) {
        if(x-0.0>=-0.0000001&&x-0.0<=0.0000001&&n<0)
            return 0.0;
        else if(n<0){
            double ans = myUnsignedPow(x,-n);
            ans = 1.0/ans;
            return ans;
        }
        else{
            double ans = myUnsignedPow(x,n);
            return ans;
        }
    }
    double myUnsignedPow(double x,unsigned int n){ 
        cout<<n<<endl;
        if(n==0)
            return 1;
        else if(n==1)
            return x;
        else{
            double ans = myUnsignedPow(x,n>>1);
            ans *= ans;
            if(n&1)
                ans*=x;
            return ans;
        }
    }
};