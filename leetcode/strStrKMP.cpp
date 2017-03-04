class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        int n = haystack.size();
        int m = needle.size();
        vector<int> pi = compute_prefix(needle);
        int q = 0;
        for(int i=0;i<n;i++){
            while(q>0&&needle[q]!=haystack[i]){
                q = pi[q];
            }
            if(needle[q]==haystack[i]){
                q++;
            }
            if(q==m)
                return i-m+1;
        }
        return -1;
    }

    vector<int> compute_prefix(string needle){
        int m = needle.size();
        vector<int> pi(m+1,0);
        int k = 0;
        pi[1] = 0;
        for(int q=2;q<=m;q++){
            while(k>0&&needle[k+1-1]!=needle[q-1]){
                k = pi[k];
            }
            if(needle[k+1-1]==needle[q-1]){
                k +=1;
            }
            pi[q] = k;
        }
        return pi;
    }
};
