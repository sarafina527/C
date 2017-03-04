class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int radius = 0;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        heaters.push_back(INT_MAX);//shaobin
        int i=0,j=0;
        vector<int> dishh = vector<int>(houses.size());
        while(i<houses.size()&&j<heaters.size()){
        	if(houses[i]<=heaters[j]){
        		dishh[i] = heaters[j]-houses[i];
        		i++;
        	}else if(houses[i]<=heaters[j+1]){
        		int ld = houses[i] - heaters[j];
        		int rd = heaters[j+1] - houses[i];
        		dishh[i] = ld<=rd?ld:rd;
        		i++;
        	}else{
        		j++;
        	}
        }
        for(int k = 0;k<dishh.size();k++){
        	if(dishh[k]>radius){
        		radius = dishh[k];
        	}
        }
        return radius;
    }
};