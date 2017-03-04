class Solution {
public:
    int longestPalindrome(string s) {
    	int ans = 0;
    	bool flag = 0;
        map<char,int> sc;
        for(int i=0;i<s.size();i++){
        	sc[s[i]]++;
        }
        for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it){
        	if(it->second%2==0){
        		ans+=it->second;
        	}else{
        		if(!flag){
        			ans+=it->second;
        			flag = 1;
        		}else{
        			ans+=it->second-1;
        		}
        	}
        }
        return ans;   

    }
    
};