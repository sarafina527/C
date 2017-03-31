class Solution {
public:
    char findTheDifference(string s, string t) {
        int book = 0;
        char ans;
        for(int i=0;i<s.size();i++){
            book ^= 1<<(s[i]-'a');
        }
        for(int i=0;i<t.size();i++){
            book ^= 1<<(t[i]-'a');
        }
        for(int i=0;i<26;i++){
            if(book&1<<i)
                ans = i+'a';
        }
        return ans;
    }
};