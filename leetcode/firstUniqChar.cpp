class Solution {
public:
    int firstUniqChar(string s) {
    	int ans = -1;
        int has = 0;
        int more = 0;
        for(int i=0;i<s.size();i++){
        	int bit = s[i]-'a';
        	if(has>>bit&1){
        		more|=1<<bit;
        	}else{
        		has|=1<<bit;
        	}
        }
        for(int i=0;i<s.size();i++){
        	int bit = s[i]-'a';
        	if(!(more>>bit&1)){
        		ans = i;
        		break;
        	}
        }
        return ans;
    }
};