class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        for(int i=1;i<=num;i++){
        	if(i&(i-1)==0){
        		ans[i] = 1;
        	}else{
        		if((i-1)&1==0)
        			ans[i] = ans[i-1]+1;
        		else{
        			int tmp = i-1,onebits=0;
        			while(tmp&1){//计算有多少个连续的1，会翻转
        				onebits++;
        				tmp = tmp>>1;
        			}
        			ans[i] = ans[i-1]-onebits+1;
        		}      		
        	}
        }
        return ans;
    }
};