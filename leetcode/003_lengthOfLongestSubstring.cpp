//3. Longest Substring Without Repeating Characters最长不重复子串
//tag: Hash Table ,Two Pointers,String
//问题描述：给定一个字符串，找到最长的子串的长度没有重复字符。
//注意点：子串和子序列的区别，子串是连续的，子序列可以是分散的
//思路：寻找字符串中的不重复的最大子串，遇重复的字符则断，重新在重复字符的下一个开始，及时改变hash表的value

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0,len = 0,p=0,q=0;
        map<char,int> pos = map<char,int>();//反向映射，字符到索引
        while(q<s.size()){
            if(pos.find(s[q])!=pos.end()&&pos[s[q]]>=p){//出现重复且出现在当前取区域
                len = q-p;
                if(len>maxlen){
                    maxlen = len;
                }               
                p = pos[s[q]]+1;//point：重新从重复字符的下一个开始检查           
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

//空间优化，当都是小写字母时，可以用一个int变量的32位中26为置1的办法标记出现
/*
 * 寻找字符串中的不重复的最大子串，遇重复的字符则断，重新开始
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxl = 0,l=0;
        int hash = 0;
        for(int i=0;i<s.size();i++){
            if(hash&1<<(s[i]-'a')){//当出现过此字符时，从当前字符重新开始
                if(l>maxl){
                    maxl = l;
                }
                l = 1;
                hash = 0;
                hash|= 1<<(s[i]-'a');
            }else{//标记并长度+1
                hash|= 1<<(s[i]-'a');
                l++;
            }           
        }
        if(l>maxl) maxl = l;//没有出现重复或者最后子串没有出现
        return maxl;
    }
};