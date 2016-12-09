class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0,len = 0,p=0,q=0;
        map<char,int> pos = map<char,int>();
        while(q<s.size()){
            if(pos.find(s[q])!=pos.end()&&pos[s[q]]>=p){//出现重复且出现在当前取区域
                len = q-p;
                if(len>maxlen){
                    maxlen = len;
                }               
                p = pos[s[q]]+1;//重新从重复字符的下一个开始检查           
                pos[s[q]] = q;//抛弃第一次出现的重复字符
            }else{
                pos[s[q]] = q;  //标记出现的字符位置
            }
            q++;
        }
        if(q-p>maxlen){
            maxlen = q-p;
        }
        return maxlen;
    }
};