#include <iostream>
#include <vector>

using namespace std;
//建立两个游标i,j，分别遍历in和out，当out[j]等于栈顶时，出栈，不等于时则压栈
bool isPossible(vectot<int> in,vector<int> out){
	vector<int> stk = vector<int>();
	for(int i = 0,j=0;j<out.size();j++){
		while(stk.empty()||stk.top()!=out[j]){
			if(i>=in.size()) return false;
			stk.push(in[i]);
			i++;
		}
		stk.pop();
	}
	return ture;
	
}