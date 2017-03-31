class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
    	if(height.size()==0) return 0;
    	vector<int> psum = presum(height);//每个位置保存之前元素之和
    	
        stack<int> index;
        map<int,int> st2area;
        int i;
        for(int j=1;j<height.size();j++){
    		
    		if(height[j]>=height[j-1]){//上升阶段
                continue;
    // 			h = height[index.top()];
    // 			s = index.top();
    // 			e = j-1;
    // 			int base = sum[e]-sum[s]+height[s];
				// int tmp = h*(e-s+1)-base;
				// if(tmp>0) ans+=tmp;
    // 			index.push(j);
    // 			maxi = j+1;
    		}else if(height[j]<height[j-1]){//开始下降
                int rh = height[j-1];
                if(!index.empty()&&index.top()<rh){
                    index.pop();
                }
                if(index.emp())
    			if()

    		}
        }
        map<int,int>::iterator it;
        for(it=st2area.begin();it!=st2area.end();it++){
        	ans+=it->second;
        }
        return ans;
    }
    vector<int> presum(vector<int>& v){
        vector<int> sum(v.size(),0);
    	for(int i=1;i<sum.size();i++){
    		sum[i] = sum[i-1]+v[i-1];
    	}
        return sum;
    }
};