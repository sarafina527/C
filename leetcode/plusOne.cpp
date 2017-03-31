class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    	vector<int> ans(digits.begin(),digits.end());
        int gewei = digits.back();
        ans[ans.size()-1] =(gewei+1)%10;
        int c = (gewei+1)/10;
        for(int i = digits.size()-2;c&&i>=0;i--){
            ans[i] = (digits[i]+c)%10;
        	c = (digits[i]+c)/10;
        }
        if(c){
        	ans.insert(ans.begin(),c);
        }
        return ans;
    }
};