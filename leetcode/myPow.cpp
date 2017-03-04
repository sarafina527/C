class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) 
            return 1;
        else if(n<0){
            return myPow(1/x,0-n);
        }
        else{
            double halfp = myPow(x,n/2);
            cout<<halfp<<endl;
            if(n%2==0){         
                return halfp*halfp;
            }else{
                return x*halfp*halfp;
            }
        }
        
    }
};