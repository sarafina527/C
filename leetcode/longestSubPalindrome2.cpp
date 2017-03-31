//递归超时
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        vector<int> book(2*s.size(),-1);
        longestPalindrome(s,0,s.size()-1,book,ans);
        return ans;
    }
    bool longestPalindrome(string &s,int p,int q,vector<int> &book,string &ans){
        int pp = p+q;
        if(book[pp]!=-1){
            if(book[pp]>=q-p+1)
                return 1;
            else
                return 0;
        }else if(q-p+1==0||p==q){
            if(q-p+1>ans.size()){
                ans = s.substr(p,q-p+1);
            }
            if(q-p+1>book[pp])
                book[pp] = q-p+1;
            return true;
        }else{
            if(s[p]==s[q]&&longestPalindrome(s,p+1,q-1,book,ans)){
                if(q-p+1>ans.size())
                    ans = s.substr(p,q-p+1);
                book[pp]+=2;
                return true;
            }else{
                longestPalindrome(s,p,q-1,book,ans);
                longestPalindrome(s,p+1,q,book,ans);
            }
        }
        return false;
    }

};
//超时

//超时
//"civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"