class Solution {
public:
    string multiply(string num1, string num2) {
    	unsigned int size = num1.size()*num2.size();
    	string ans(size,0);
    	string longstr,shstr;
    	if(num1.size()>=num2.size()){
    		longstr = num1;
    		shstr = num2;
    	}else{
    		longstr = num2;
    		shstr = num1;
    	}
    	
        return "";
    }

    string addStrings(string num1, string num2) {
        string ans(10201,0);
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        int c = 0,i=0;
        for(;i<num1.size()&&i<num2.size();i++){
            int cur = (num1[i]-'0')+(num2[i]-'0')+c;
            c = cur/10;
            ans[i] = cur%10+'0';
        }
        if(num1.size()>num2.size()){
            for(;i<num1.size();i++){
                int cur = (num1[i]-'0')+c;
                c = cur/10;
                ans[i] = cur%10+'0';
            }
        }else if(num1.size()<num2.size()){
            for(;i<num2.size();i++){
                int cur = (num2[i]-'0')+c;
                c = cur/10;
                ans[i] = cur%10+'0';
            }
        }
        if(c)
            ans[i] = c+'0';
        
        for(int i=ans.size()-1;i>0&&ans[i]==0;i--){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};