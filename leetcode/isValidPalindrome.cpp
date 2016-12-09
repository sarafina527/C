class Solution {
public:
    bool isPalindrome(string s) {
    	//转小写
        for(int i=0;i<s.size();i++){
        	if(s[i]>='A'&&s[i]<='Z'){
        		s[i] = s[i]-'A'+'a';
        	}
        }
        int p = 0 , q = s.size()-1;
        while(p<q){
        	while(!((s[p]>='a'&&s[p]<='z')||(s[p]>='0'&&s[p]<='9'))){
        		p++;
        	}
        	while(!((s[q]>='a'&&s[q]<='z')||(s[q]>='0'&&s[q]<='9'))){
        		q--;
        	}
        	if(p<q&&s[p]!=s[q]){
        		return false;
        	}else{
        		p++;
        		q--;
        	}
        }
        return true;
    }
};