class Solution {
public:
    bool isValid(string s) {
        map<char,int> table = map<char,int>();
        table['('] = -1;table['{'] = -2;table['['] = -3;
        table[')'] = 1;table['}'] = 2;table[']'] = 3;
        stack<char> stk = stack<char>();
        for(int i=0;i<s.size();i++){
        	if(table[s[i]]<0){
        		stk.push(s[i]);
        	}else{
        		if(stk.empty()){
        			return 0;
        		}
        		char t = stk.top();
        		if(table[s[i]]+table[t]==0){
        			stk.pop();
        		}else{
        			return 0;
        		}
        	}
        }
        if(stk.empty()){
        	return 1;
        }else{
        	return 0;
        }
    }
};