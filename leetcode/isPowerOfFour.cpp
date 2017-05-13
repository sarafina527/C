class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num&(num-1))
        	return false;
        else{
        	while(num>=4){
        		num = num>>2;
        	}
        	if(num==1)
        		return true;
        	else
        		return false;
        }
    }
};