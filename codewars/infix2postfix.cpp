std::string to_postfix(const std::string& infix) {
	std::string postfix = std::string();
	std::stack<char> s = std::stack<char>();
	std::map<char, int> prior = std::map<char,int>();
	prior['+']=0;prior['-']=0;prior['*']=2;prior['/']=2;prior['^']=3;prior['(']=5;prior[')']=-1;
	for(int i=0;i<infix.size();i++){
		if(!s.empty())
			std::cout<<s.top()<<std::endl;
		if(infix[i]>='0'&&infix[i]<='9'){//遇数字直接输出
			postfix.push_back(infix[i]);
		}else if(infix[i]==')'){//遇右括号压入堆栈,一直输出栈顶，直到3遇到左括号
			while(s.top()!='('&&!s.empty()){
				postfix.push_back(s.top());
				s.pop();
			}      		
			s.pop();
		}else if(s.empty()||s.top()=='('||prior[infix[i]]>prior[s.top()]){//若栈顶小于当前，继续压栈
			s.push(infix[i]);
			
		}else if(prior[infix[i]]<=prior[s.top()]){//若栈顶优先级比当前符高则输出栈顶，并重新比较新的
			postfix.push_back(s.top());
			s.pop();
			i--;//游标驻留
		}
	}
	while(!s.empty()){
		postfix.push_back(s.top());
		s.pop();
	}

    return postfix;
}