class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int ln=0,rn=0;
        string sofar;
        vector<string> ans;
        generateParenthesis(n,ln,rn,sofar,ans);
        return ans;
    }
    void generateParenthesis(int n,int ln,int rn,string sofar,vector<string> &ans){
    	if(ln==n&&rn==n)
    		ans.push_back(sofar);
    	else{
    		if(ln<=rn||rn==n){
    			sofar.push_back('(');
    			generateParenthesis(n,ln+1,rn,sofar,ans);
    		}else if(ln==n){
    			sofar.push_back(')');
    			generateParenthesis(n,ln,rn+1,sofar,ans);
    		}else if(ln<n||rn<n){
    			sofar.push_back('(');
    			generateParenthesis(n,ln+1,rn,sofar,ans);
    			sofar[sofar.size()-1] = ')';
    			generateParenthesis(n,ln,rn+1,sofar,ans);
    		}
    	}
    }
};