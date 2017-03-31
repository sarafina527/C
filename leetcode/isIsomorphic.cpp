class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	if(s.size()!=t.size()) return false;
    	map<char,char> s2t,t2s;
    	for(int i=0;i<s.size();i++){
    		if(s2t.find(s[i])==s2t.end()&&t2s.find(t[i])==t2s.end()){
    			s2t[s[i]] = t[i];
    			t2s[t[i]] = s[i];
    		}	
    		else if(s2t.find(s[i])!=s2t.end()&&s2t[s[i]]!=t[i]||t2s.find(t[i])!=t2s.end()&&t2s[t[i]]!=s[i]){
    			return false;
    		}	
    	}
        return true;
    }
};