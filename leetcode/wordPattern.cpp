class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> strs;
        int found = str.find(' '),pre =0;
        while(found!=string::npos){
        	string tmp = str.substr(pre,found-pre);
        	strs.push_back(tmp);
        	pre = found+1;
        	found = str.find(' ',pre);
        }
        if(pattern.size()!=strs.size()) return false;
        map<char,string> ch2str;
        map<string,char> str2ch;
        for(int i=0;i<pattern.size();i++){
        	if(ch2str.find(pattern[i])==ch2str.end()&&str2ch.find(strs[i])==str2ch.end()){
        		ch2str[pattern[i]] = strs[i];
        		str2ch[strs[i]] = pattern[i];
        	}else if(ch2str[pattern[i]]!=strs[i]||str2ch[strs[i]]!=pattern[i])
        		return false;
        }
        return true;

    }
};