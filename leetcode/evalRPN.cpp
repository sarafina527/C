class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> opnums;
        for(int i=0;i<tokens.size();i++){
            string cur = tokens[i];
            if(cur.size()>0)
                if(isdigit(cur[cur.size()-1]))
                    opnums.push(stringToInteger(cur));
                else{
                    int a,b;
                    if(!opnums.empty()){
                        a = opnums.top();
                        opnums.pop();
                    }else
                        break;
                    if(!opnums.empty()){
                        b = opnums.top();
                        opnums.pop();
                    }else
                        break;
                    if(cur=="+")
                        opnums.push(a+b);
                    else if(cur=="-")
                        opnums.push(b-a);
                    else if(cur=="*")
                        opnums.push(b*a);
                    else if(cur=="/")
                        opnums.push(b/a);
                }
        }
        return opnums.top();
    }
    int stringToInteger(const string& str) {
        std::istringstream stream(str);
        stream >> std::setbase(10);
        int value;
        stream >> value;
        return value;
    }
};