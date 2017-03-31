class Solution {
public:
    string toHex(int num) {
    	unsigned int unum = num;
      	map<int,char> lookup;
      	for(int i=0;i<=9;i++){
      		lookup[i] = i+'0';
      	}
      	for(int i=10;i<=15;i++){
      		lookup[i] = i-10+'a';
      	}
      	string ans;
      	unsigned int mask = 15;
      	bool leadzero = true;
      	for(int i=28;i>=0;i-=4){
      		int tmp = unum>>i;
      		tmp = tmp&mask;
      		if(tmp!=0||leadzero==0){
      			leadzero = 0;
      			ans.push_back(lookup[tmp]);
      		}
      	}
      	if(ans.size()==0) ans.push_back('0');
      	return ans;
    }
};