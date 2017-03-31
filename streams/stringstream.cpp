#include <sstream>
#include <iterator>
#include <vector> 
#include <iostream>
using namespace std;
//字符串流


//0. 将字符串注入到字符串流
//1.>> 将空格作为分割符，
vector<string> split(string input){
	stringstream stream(input);
	vector<string> words;
	words.insert(words.begin(),istream_iterator<string>(stream),istream_iterator<string>());
	return words;
}
void printv(vector<string> v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<",";
	}
	cout<<endl;
}
int main(){
	string str = "wo shi  zui  bang de ";
	vector<string> words = split(str);
	printv(words);
	return 0;

}
