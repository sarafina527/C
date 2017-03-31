class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxpro = 0;
        if(prices.size()>1){
        	vector<int> behindmax(prices.size(),0);
        	behindmax[behindmax.size()-1] = prices.back();
        	for(int i = prices.size()-2;i>=0;i--){
        		if(prices[i]>behindmax[i+1])
        			behindmax[i] = prices[i];
        		else
        			behindmax[i] = behindmax[i+1];
        	}
	        for(int i=prices.size()-1;i>=0;i--){
	        	if(maxpro<behindmax[i]-prices[i])
	        		maxpro = behindmax[i]-prices[i];
	        }
        }
        return maxpro;
    }
};