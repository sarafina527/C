class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int n = gas.size();
    	map<int,int> revleft;
        for(int i=0;i<n;i++){
        	revleft[gas[i]-cost[i]] = i;
        }
        map<int,int>::iterator iter;
        for(iter=revleft.begin();iter!=revleft.end();iter++){
        	int start = iter.sencond;
        	int tank = gas[start];
        	for(int i = start;tank>cost[i];){
        		tank = tank-cost[i]+gas[i+1];
        		i = (i+1)%n;
        	}
        	if(i+1==start)
        		return start;
        }
        return -1;
    }
};

[2,4]
[3,4]
[1,2]
[2,1]