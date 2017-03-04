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