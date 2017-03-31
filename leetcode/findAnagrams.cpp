class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    	vector<int> ans;
        map<char,int> pcount;
        map<char,int> sscount;
        for(int i=0;i<p.size();i++){
        	pcount[p[i]]++;
        }
        for(int i=0;i<p.size();i++)
        	sscount[s[i]]++;
    	if(checkEqual(pcount,sscount)){
    		ans.push_back(0);
    	}
        for(int i=p.size();i<s.size();i++){
        	sscount[s[i-p.size()]]--;
        	sscount[s[i]]++;
        	if(checkEqual(pcount,sscount)){
        		ans.push_back(i-p.size()+1);
        	}
        }
        return ans;
    }
    bool checkEqual(map<char,int>& pcount,map<char,int>& sscount){
    	map<char,int>::iterator it;
    	for(it=pcount.begin();it!=pcount.end();it++){
    		if(sscount[it->first]!=pcount[it->first])
    			return false;
    	}
    	return true;
    }
};