class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        int tackover = 0;
        int curbit = 0;
        for(int i=0;i<32;i++){
            if(tackover){
                tackover = (a>>i&1)|(b>>i&1);
                if((a>>i&1)^(b>>i&1))
                    curbit = 0;
                else
                    curbit = 1;
            }else{
                tackover = (a>>i&1)&(b>>i&1);
                curbit = (a>>i&1)^(b>>i&1);
            }
            if(curbit)
                ans|=1<<i;
        }
        return ans;
    }
};