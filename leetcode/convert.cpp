class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        string ans = string();
        if(numRows==2){
        	for(int i=0;i<s.size();i+=2){
        		ans.push_back(s[i]);
        	}
        	for(int i=1;i<s.size();i+=2){
        		ans.push_back(s[i]);
        	}
        	return ans;
        }
        int c = (s.size()/(2*(r-1))+1)*(r-1);
    }
};