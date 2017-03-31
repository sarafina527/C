class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n,"");
        for(int i=1;i<=n;i++){
        	if(i%15==0)
        		ans[i-1] = "FizzBuzz";
        	else if(i%5==0)
        		ans[i-1] = "Buzz";
        	else if(i%3==0)
        		ans[i-1] = "Fizz";
        	else 
        		ans[i-1] = toString(i);
        }
        return ans;
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