#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
void printv(vector<int> & v){
	for(int i=0;i<v.size();i++)
		cout<<v[i];
	cout<<endl;
}
int main(){

	string roll;
	cin>>roll;
	vector<int> shazi;
	for(int i=1;i<=6;i++){
		shazi.push_back(i);
	}
	for(int i=0;i<roll.size();i++){
		char c = roll[i];
		if(c=='C'){
			int tmp = shazi[0];
			shazi[0] = shazi[2];
			shazi[2] = shazi[1];
			shazi[1] = shazi[3];
			shazi[3] = tmp;
		}else if(c=='A'){
			int tmp = shazi[3];
			shazi[3] = shazi[1];
			shazi[1] = shazi[2];
			shazi[2] = shazi[0];
			shazi[0] = tmp;
		}else if(c=='F'){
			int tmp = shazi[3];
			shazi[3] = shazi[5];
			shazi[5] = shazi[2];
			shazi[2] = shazi[4];
			shazi[4] = tmp;
		}else if(c=='B'){
			int tmp = shazi[4];
			shazi[4] = shazi[2];
			shazi[2] = shazi[5];
			shazi[5] = shazi[3];
			shazi[3] = tmp;
		}else if(c=='L'){
			int tmp = shazi[0];
			shazi[0] = shazi[4];
			shazi[4] = shazi[1];
			shazi[1] = shazi[5];
			shazi[5] = tmp;
		}else if(c=='R'){
			int tmp = shazi[5];
			shazi[5] = shazi[1];
			shazi[1] = shazi[4];
			shazi[4] = shazi[0];
			shazi[0] = tmp;
		}

	}
 printv(shazi);
	return 0;
} 
