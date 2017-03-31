//299. Bulls and Cows
//tag: Hash Table
//问题描述：给出两个串Secret和guess，同位置上相同字符的是bull，不同位置上有相同的数是cow 
//样例：Secret number: "1807" ,guess: "7810"  返回："1A3B"
class Solution {
public:
    string getHint(string secret, string guess) {
    	int bulls = 0,cows = 0;
    	map<int,int> setb,gutb;
        for(int i=0;i<secret.size()&&i<guess.size();i++){
        	if(secret[i]==guess[i])
        		bulls++;
        	else{
        		setb[secret[i]]++;
        		gutb[guess[i]]++;
        	}
        }
        map<int,int>::iterator it;
        for(it=setb.begin();it!=setb.end();it++){
        	int cur = it->first;
        	int secnt = it->second;
        	if(gutb.find(cur)!=gutb.end()){
        		if(gutb[cur]>secnt)
        			cows+=secnt;
        		else
        			cows+=gutb[cur];
        	}
        }
        string ans(intToString(bulls));
        ans.push_back('A');
        ans += intToString(cows);
        ans.push_back('B');
        return ans;
    }
    string intToString(int n) {
      ostringstream stream;
      stream << n;
      return stream.str();
    }
};