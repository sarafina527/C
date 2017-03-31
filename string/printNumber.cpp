//egnore the begin zero
void printNumber(string s){
	bool beginzero = 1;
	for(int i=0;i<s.size();i++){
		if(beginzero&&s[i]!='0')
			beginzero = 0;
		if(!beginzero)
			cout<<s[i];
	}
}