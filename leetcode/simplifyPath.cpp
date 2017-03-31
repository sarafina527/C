class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        for(int i=0;i<path.size();){
            while(path[i]=='\/')
                i++;
            size_t found = path.find('\/',i);
            string tmp;
            if(found!=string::npos){
                tmp = path.substr(i,found-i);
                i = found+1;
            }else{
                tmp = path.substr(i);
                i = path.size();
            }
            if(tmp.compare("..")==0){
                if(stack.size())
                    stack.pop_back();
            }else if(tmp.compare(".")==0){
                continue;
            }else{
                stack.push_back(tmp);
            }
        }
        string ans = "\/";
        for(int i=0;i<stack.size();i++){
            ans = ans+stack[i];
            ans.push_back('\/');
        }
        while(ans.size()>1&&ans.back()=='\/')
            ans.pop_back();
        return ans;
    }
};