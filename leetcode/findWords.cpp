class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    	vector<string> ans;
        string row1 = "qwertyuiop";
        string row2 = "asdfghjkl";
        string row3 = "zxcvbnm";
        map<char,int> ch2h;
        reverse(row1,ch2h,1);
        reverse(row2,ch2h,2);
        reverse(row3,ch2h,3);
        for(int i=0;i<words.size();i++){
        	if(checkSameh(words[i],ch2h))
        		ans.push_back(words[i]);
        }
        return ans;
    }
    void reverse(string str,map<char,int> &ch2h,int r){
    	for(int i=0;i<str.size();i++){
    		ch2h[str[i]] = r;
    	}
    }
    bool checkSameh(string str,map<char,int> ch2h){
    	if(str.size()==0) return 1;
    	if(str[0]<'a')
    		str[0] = str[0]-'A'+'a';
    	int h = ch2h[str[0]];
    	for(int i=1;i<str.size();i++){
    		if(str[i]<'a')
    			str[i] = str[i]-'A'+'a';
    		if(ch2h[str[i]]!=h)
    			return false;
    	}
    	return true;
    }
};