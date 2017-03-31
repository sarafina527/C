//tag: Hash Table
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> strmap;
        for(int i=0;i<strs.size();i++){
        	string tmp = strs[i];
        	sort(tmp.begin(),tmp.end());
        	if(strmap.find(tmp)!=strmap.end())
        		strmap[tmp].push_back(strs[i]);
        	else{
        		vector<string> vectmp(1,strs[i]);
        		strmap[tmp] = vectmp;
        	}
        }
        map<string,vector<string>> ::iterator it;
        for(it=strmap.begin();it!=strmap.end();it++){
        	vector<string> vectmp = it->second;
        	sort(vectmp.begin(),vectmp.end());
        	ans.push_back(vectmp);
        }
        return ans;
    }
};