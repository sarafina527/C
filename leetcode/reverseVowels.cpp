/*
 * 只翻转元音字母
 */
class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
        	while(!isVowel(s[i])){
        		i++;
        	}
        	while(!isVowel(s[j])){
        		j--;
        	}
        	if(i<j){
        		char tmp = s[i];
	        	s[i++] = s[j];
	        	s[j--] = tmp;
        	}
        	
        }
        return s;
    }
    bool isVowel(char c){
    	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
    		return true;
    	}else{
    		return false;
    	}
    }
};