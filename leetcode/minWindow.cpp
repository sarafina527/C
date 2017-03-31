class Solution {
public:
    string minWindow(string s, string t) {
    	string ans = s;
        map<char,int> isint;//用于统计各个字符的数量
        map<char,int> curint;//用于计数
        for(int i=0;i<t.size();i++){
        	isint[t[i]]++;
        }
        int i=0,j=0;
        bool flag = 0;
        queue<int> q;
        for(i=0,j=0;i<s.size()&&j<s.size();j++){
        	if(isint.find(s[i])==isint.end()){//找到第一个t中元素
        		i++;
        	}else{
        		if(isint.find(s[j])!=isint.end()){//判断是否是t中元素
        			curint[s[j]]++;
        			q.push(j);
        			while(!q.empty()&&checkContain(curint,isint)){//满足要求了
        				flag = 1;
        				string tmp = s.substr(i,j-i+1);
        				if(tmp.size()<ans.size())
        					ans = tmp;
        				curint[s[i]]--;
        				q.pop();
        				i = q.front();//从下一个开始对比
        			}
        		}	
        	}
        }
        ans = flag?ans:"";
        return ans;
    }
    bool checkContain(map<char,int> &curint,map<char,int> &isint){
    	map<char,int>::iterator it;
    	for(it = isint.begin();it!=isint.end();it++){
    		if(curint[it->first]<isint[it->first])
    			return false;
    	}
    	return true;
    }
};