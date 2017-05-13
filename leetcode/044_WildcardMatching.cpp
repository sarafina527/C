class Solution {
public:
    bool isMatch(string s, string p) {
        int sp=0,pp=0,star=-1,match;
        while(sp<s.size()){
            if(pp<p.size()&&(p[pp]=='?'||s[sp]==p[pp])){
                sp++;
                pp++;
            }else if(pp<p.size()&&p[pp]=='*'){//find star
                star = pp;
                match = sp;//next
                pp++;
            }else if(star!=-1){
                match++;
                sp = match;//match 从s的哪里开始和*后面对比
                pp = star+1;
            }else
                return false;
        }
        while(pp<p.size()&&p[pp]=='*')
            pp++;
        if(pp==p.size())
            return true;
        else
            return false;
    }
};