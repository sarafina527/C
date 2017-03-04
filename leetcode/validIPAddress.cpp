class Solution {
public:
    string validIPAddress(string IP) {
    	string ans = "Neither";
    	vector<string> grps;
    	int fp=-1,fc=-1;
        while((fc = IP.find('.',fp))!=-1){//可能是IPV4
        	string tmp = IP.substr(fp+1,fc-fp-1);
        	if(tmp.size()<=0) return "Neither";
        	if(tmp.size()>1&&tmp[0]=='0'||tmp.size()>3){
        		return "Neither";
        	}
        	int value = tmp[0]-'0';
        	for(int t = 1;t<tmp.size();t++){
        		value = value*10+tmp[t];
        	}
        	if(value>=0&&value<=255){
        		ans = "IPv4";
        	}else{
        		return "Neither";
        	}
        	
        }
        while((fc = IP.find(':',fp))!=-1){
        	string tmp = IP.substr(fp+1,fc-fp-1);
        	cout<<tmp<<endl;
        	if(tmp.size()<=0||tmp.size()>4) return "Neither";
        	for(int t=0;t<tmp.size();t++){
        		char c = tmp[t];
        		if(c>='0'&&c<='9') continue;
        		if(c>='a'&&c<='f') continue;
        		if(c>='A'&&c<='F') continue;
        		return "Neither";
        	}
        	ans = "IPv6";
        }
        return ans;
    }
};