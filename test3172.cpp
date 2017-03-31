#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
    void deleteTailSpace(string &s){
    	while(s[s.size()-1]==' ')
    		s.erase(s.size()-1);
    }
    void eraseRepeatSpace(string &s){
    	for(int i=1;i<s.size();i++){
    		if(s[i]==' '){
    			int j;
    			for(j=i+1;j<s.size()&&s[j]==' ';j++);
    			if(j>i+1)
    				s.erase(i+1,j-i-1);
    		}	
    	}
    }
void reverseWords(string &s) {
    	deleteTailSpace(s);
    	eraseRepeatSpace(s);
        for(int i=0,j=s.size()-1;i<j;i++,j--){
        	char tmp = s[i];
        	s[i] = s[j];
        	s[j] = tmp;
        }
        deleteTailSpace(s);
        int found,i=0;
        while((found = s.find(' ',i))!=string::npos){
        	int j = found -1;
        	while(i<j){
        		char tmp = s[i];
        		s[i++] = s[j];
        		s[j--] = tmp;
        	}
        	i = found+1;
        }
        int j = s.size()-1;
        while(i<j){
        	char tmp = s[i];
        	s[i++] = s[j];
        	s[j--] = tmp;
        }
    }

    
    int main(){
    	string s = "   a   b  c d   e  ";
    	reverseWords(s);
    	cout<<s<<endl;
	}
