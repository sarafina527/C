class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        vector<int> code;
        readBinaryWatch(10,num,code,ans);
        return ans;
    }
    void readBinaryWatch(int n,int k,vector<int> sofar,vector<string> &ans) {//n空的个数，k剩余
        if(n==k||k==0||overhour(sofar)||overminute(sofar)){//base case n==k提前将不合情况去除
        	if(overhour(sofar)||overminute(sofar))
        		return;
        	else{
        		while(sofar.size()<10){
	        		if(n==k)
		    			sofar.push_back(1);
		    		else
		    			sofar.push_back(0);
	        	}
	        	ans.push_back(trans(sofar));
        	}
        	
        }else{
        	sofar.push_back(0);
        	readBinaryWatch(n-1,k,sofar,ans);
        	sofar[sofar.size()-1] = 1;
        	readBinaryWatch(n-1,k-1,sofar,ans);
        }
    }
    string trans(vector<int> v){
    	int h = 0,m = 0;
    	for(int i=0;i<4;i++){
    		h=2*h+v[i];
    	}
    	for(int i=4;i<v.size();i++){
    		m=2*m+v[i];
    	}
    	string ans;
    	if(h>=10)
    		ans+=(h/10+'0');
    	ans+=(h%10+'0');
    	ans+=":";
        ans+=(m/10+'0');
    	ans+=(m%10+'0');
    	return ans;
    }
    bool overhour(vector<int> v){
    	if(sofar.size()>=2&&sofar[0]==1&&sofar[1]==1)
    		return 1;
    	else
    		return 0;
    }
    bool overminute(vector<int> m){
    	if(m.size()<=4)
    		return false;
    	else{
    		int m = 0;
    		for(int i=4;i<m.size();i++){
    			m = 2*m+m[i];
    		}
    		if(m>59)
    			return true;
    		else
    			return false;
    	}
    }

};