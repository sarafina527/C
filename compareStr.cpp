bool compare(std::string s1, std::string s2)
{
    int sum1=0,sum2=0;    
    for(int i=0;i<s1.size();i++){
    	if(s1[i]>='a'&&s1[i]<='z'){
    		s1[i] = s1[i]+'A'-'a';
    		sum1 += s1[i];
    	}else if(s1[i]>='A'&&s1[i]<='Z'){
    		sum1 += s1[i];
    	}else{
    		sum1 = 0;
    		break;
    	}    	
    }
    for(int i=0;i<s2.size();i++){
    	if(s2[i]>='a'&&s2[i]<='z'){
    		s2[i] = s2[i]+'A'-'a';
    		sum2+=s2[i];
    	}
    	else if(s2[i]>='A'&&s2[i]<='Z'){
    		sum2+=s2[i];
    	}else{
    		sum2 = 0;
    		break;
    	}
    	
    }
    if(sum1==sum2){
    	return 1;
    }else{
    	return 0;
    }
}