class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        vector<bool> sofar;
        grayCode(n,sofar,ans);
        return ans;
    }
    void grayCode(int rest,vector<bool> sofar,vector<int> &ans){
    	if(rest==0)
    		ans.push_back(todec(sofar));
    	else{
    		bool sw = sum(sofar)%2;
    		sofar.push_back(sw);
    		grayCode(rest-1,sofar,ans);
    		sofar[sofar.size()-1] = !sofar.back();
    		grayCode(rest-1,sofar,ans);
    	}

    }
	int todec(vector<bool> &v){
		int ans = 0;
		for(int i=0;i<v.size();i++){
			ans = 2*ans+v[i];
		}
		return ans;
	}
	int sum(vector<bool> &v){
		int ans = 0;
		for(int i=0;i<v.size();i++){
			ans+=v[i];
		}
		return ans;
	}
};