class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> strnums(nums.size(),"");
        for(int i=nums.size()-1;i>=0;i--){
            strnums[i] = toString(nums[i]);
        }
        sort(strnums.begin(),strnums.end(),cmp);
        for(int i=strnums.size()-1;i>=0;i--){
            ans+=strnums[i];
        }
        while(ans[0]=='0'&&ans.size()>1){
            ans = ans.substr(1);
        }
        return ans;
    }
    static bool cmp(string num1,string num2){
        string eqlen1 = num1+num2;
        string eqlen2 = num2+num1;
        char * cstr1 = new char [eqlen1.length()+1];
        char * cstr2 = new char [eqlen2.length()+1];
        strcpy(cstr1,eqlen1.c_str());
        strcpy(cstr2,eqlen2.c_str());
        int ans = strcmp(cstr1,cstr2);
        return ans<0;
    }
    string toString(int num){
        string ans;
        if(num==0)
            return "0";
        while(num){
            char tmp = (num%10+'0');
            ans.push_back(tmp);
            num/=10;
        }
        ans = reverse(ans);
        return ans;
    }
    string reverse(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            char tmp = s[i];
            s[i++] = s[j];
            s[j--] = tmp;
        }
        return s;
    }
};