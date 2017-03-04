class Solution {
public:
    int lengthOfLastWord(string s) {
    	while(s[s.size()-1]==' '){
    		s.pop_back();
    	}
        int p = s.find_last_of(' ');
        return s.size()-p-1;
    }
};