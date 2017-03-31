class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        vector<string> lookup;
        string sofar;
        lookup.push_back(" ");
        lookup.push_back("");
        lookup.push_back("abc");
        lookup.push_back("def");
        lookup.push_back("ghi");
        lookup.push_back("jkl");
        lookup.push_back("mno");
        lookup.push_back("pqrs");
        lookup.push_back("tuv");
        lookup.push_back("wxyz");
        letterCombinations(digits,sofar,lookup,ans);
        return ans;

    }
    void letterCombinations(string digits,string sofar,vector<string> &lookup,vector<string> &ans){
    	if(digits.size()==0)
    		ans.push_back(sofar);
    	else{
    		string options = lookup[digits[0]-'0'];
    		for(int i=0;i<options.size();i++){
    			string next = sofar+options[i];
    			string rest = digits.substr(1);
    			letterCombinations(rest,next,lookup,ans);
    		}
    	}
    }
};