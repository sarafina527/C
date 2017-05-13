class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	vector<int> diff(gas.size(),0);
    	set<int> cand;
    	for(int i=0;i<gas.size();i++){
    		diff[i] = gas[i] - cost[i];
    		if(diff[i]>=0)
    			cand.insert(i);
    	}
    	set<int>::iterator it;
    	for(it=cand.begin();it!=cand.end();it++){
    		int st = *it,cur,gasleft=diff[st];
    		for(cur=st+1;;cur++){
    			if(cur==gas.size()) cur = 0;//环
    			if(cur==st) return st;
    			if(gasleft+diff[cur]<0) break;//撑不到下一站
    			gasleft +=diff[cur];
    		}
    	}
    	return -1;
    }
};