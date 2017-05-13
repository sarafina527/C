class Solution {
public:
    int maxProduct(vector<string>& words) {
    	vector<int> book(words.size(),0);
    	int ans = 0;
        for(int i=0;i<words.size();i++){
        	for(int j=0;j<words[i].size();j++){
        		int c = words[i][j]-'a';
        		book[i]|=(1<<c);
        	}
        }
        for(int i=0;i<words.size();i++){
        	for(int j=i+1;j<words.size();j++){
        		if((book[i]&book[j])==0){
        			int tmp = words[i].size()*words[j].size();
        			if(ans<tmp)
        				ans = tmp;
        		}
        	}
        }
        return ans;
    }
};