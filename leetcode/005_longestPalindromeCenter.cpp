//5.Longest Palindromic Substring
//tag: String
//问题描述：给定一个字符串的最长的回文子串，
//假设：最大长度是1000。
//中心扩展法,依次以第i个字符作为中心，分别假设是奇数或偶数个回文 向两边延伸，然后与最长长度对比长度
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int maxcenter = 0;
        int maxlen = 0;
        bool oddflag = 0;
        for(int i=0;i<s.size();i++){
            int pre = i-1,behind = i+1,ilen=1;
            while(pre>=0&&behind<s.size()){//奇数
                if(s[pre--]==s[behind++])
                    ilen+=2;
                else
                    break;
            }
            if(ilen>maxlen){
                maxlen = ilen;
                maxcenter = i;
                oddflag = 1;
            }
            pre = i,behind = i+1,ilen = 0;
            while(pre>=0&&behind<s.size()){
                if(s[pre--]==s[behind++])
                    ilen+=2;
                else
                    break;
            }
            if(ilen>maxlen){
                maxlen = ilen;
                maxcenter = i;
                oddflag = 0;
            }
        }
        if(oddflag)
            ans=s.substr(maxcenter-maxlen/2+1,maxlen);
        else
            ans = s.substr(maxcenter-maxlen/2+1,maxlen);
        return ans;
    }
};

//超时样例
//"civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"