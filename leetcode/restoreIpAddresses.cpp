class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string sofar;
        restoreIpAddresses(s,4,sofar,ans);
        return ans;
    }
    void restoreIpAddresses(string rests,int restp,string sofar,vector<string> &ans){
    	if(restp==0&&rests.size()==0){
    		sofar.pop_back();
    		ans.push_back(sofar);

    	}else if(rests.size()<=restp*3||rests.size()>restp){    		
    		for(int i=1;i<=3;i++){
    			if(i>=rests.size()-(restp-1)*3&&i<=rests.size()-(restp-1)){
    				string tmp = rests.substr(0,i);
	    			string rest = rests.substr(i);
	    			string newfar = sofar+tmp+'.';
	    			if(todec(tmp)<256){
	    				cout<<tmp<<endl;
	    				restoreIpAddresses(rest,restp-1,newfar,ans);
	    			}
    			}
    			
    		}
    	}
    }
    int todec(string s){
    	int ans = 0;
    	for(int i=0;i<s.size();i++){
    		ans = 10*ans+s[i];
    	}
    	return ans;
    }
};