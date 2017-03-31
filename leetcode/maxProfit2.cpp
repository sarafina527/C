class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        if(prices.size()>1){
        	bool flag = 0;//未买入
        	int curbuy;
        	for(int i=0;i<prices.size();i++){
        		if(!flag&&i<prices.size()-1&&prices[i]<prices[i+1]){//目前最小的买入
        			flag = 1;
        			curbuy = prices[i];
        		}else if(flag&&prices[i]>curbuy&&(i+1==prices.size()||prices[i]>=prices[i+1])){//遇到比后面大的卖出
        			flag = 0;
        			maxProfit+=prices[i]-curbuy;
        		}	
        	}
        }
        return maxProfit;
    }
};