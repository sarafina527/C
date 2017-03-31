class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size()==0||strs[0].length()==0) return "";
        for(int i=0;i<strs[0].length();i++){
            char curc = strs[0][i];         
            for(int j=1;j<strs.size();j++){
                if(strs[j].size()<i+1||strs[j][i]!=curc){//出现不同时退出循环
                    return strs[0].substr(0,i);
                }     
            }           
        }
        return strs[0];
    }
};