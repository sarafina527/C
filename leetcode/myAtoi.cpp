class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        bool flag = 1;//postive
        long long ans = 0;
        while(i<str.size()&&str[i]==' '){//omit the white space
        	i++;
        }
        if(i<str.size()&&str[i]=='-'){
        	flag = 0;
        	i++;
        }else if(i<str.size()&&str[i]=='+'){
        	i++;
        }
        while(i<str.size()&&str[i]>='0'&&str[i]<='9'){
        	ans = ans*10+(long long)(str[i]-'0');
        	cout<<ans<<endl;
        	if(flag&&ans>INT_MAX){
        		return INT_MAX;
        	}else if(!flag&&ans>(long long)INT_MAX+1){
        		return INT_MIN;
        	}
        	i++;
        }
        if(!flag){
        	ans = -ans;
        }
        return ans;
    }
};