class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        vector<int> rest;
        for(int i=1;i<=n;i++){
        	rest.push_back(i);
        }
        return ans;
    }
    string permute(vector<int> &rest,int k,string &ans){//n个option,第k个排列
    	if(rest.size()==0){
    		return ans;
    	}
    	int f = factorial(n-1);
        int subt = k/f;//前面有subt个子树
        ans.push_back(rest[subt]+'0');
        rest.erase(subt);
        return getPermutation(rest,k%f,ans);
    }
    int factorial(int n){
    	if(n==0)
    		return 1;
    	else
    		return n*factorial(n-1);
    }
};