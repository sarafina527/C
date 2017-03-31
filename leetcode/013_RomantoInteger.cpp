class Solution {
public:
    int romanToInt(string s) {
    	map<char,int> lookup;
    	lookup['M'] = 1000;
    	lookup['D'] = 500;
    	lookup['C'] = 100;
    	lookup['L'] = 50;
    	lookup['X'] = 10;
    	lookup['V'] = 5;
    	lookup['I'] = 1;
    	int ans = 0;
        for(int i=0;i<s.size();){
        	if(lookup.find(s[i]) == lookup.end())
        		return -1;
        	int j = i+1;
        	while(s[j]==s[i]){
        		j++;
        	}
        	if(lookup[s[j]]<lookup[s[i]]){
        		ans+=lookup[s[i]]*(j-i);
        		i=j;
        	}else{
        		ans = ans+lookup[s[j]]-lookup[s[i]]*(j-i);
        		i=j+1;
        	}
        }
        return ans;
    }
};