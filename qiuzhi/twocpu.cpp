#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
	int n;
	//cin>>n;
	ifstream fin("input.txt");
	fin>>n;


	vector<int> tasks(n,0);
	if (! fin.is_open())  
    { 
    	cout << "Error opening file"; 
   		return 1; 
   	} 
	for(int i=0;i<n;i++){
		int tmp;
		//cin>>tasks[i];
		fin>>tmp;
		tasks[i] = tmp/1024;
		cout<<tasks[i]<<" ";
	}
	cout<<endl;
	sort(tasks.begin(), tasks.end());
	vector<bool> used(n,0);

	long long curt = 0,pt1=tasks[n-1],pt2=tasks[n-2];
	used[n-1]=1;
	used[n-2]=1;
	for(int t=0;t<n-2;t++){
		int next;
		for(int i=0;i<n;i++){
			if(!used[i]){
				next = i;
				if(tasks[i]+pt2>=pt1) break;
			}
		}
		cout<<tasks[next]<<" ";
		used[next]=1;
		int tmp = pt1;
		pt1 = tasks[next]+pt2;
		pt2 = tmp;
	}
	cout<<endl;
	cout<<pt1<<" "<<pt2<<endl;
	// for(int i=n-1;i>=0;i--){
	// 	if(curt==pt1){
	// 		cout<<1<<" "<<pt1<<" "<<tasks[i]<<endl; 
	// 		pt1 += tasks[i];
	// 	}else if(curt==pt2){
	// 		cout<<2<<" "<<pt2<<" "<<tasks[i]<<endl; 
	// 		pt2 += tasks[i];
			
	// 	}
	// 	curt = pt1<=pt2?pt1:pt2;
	// }
	cout<<(pt1>pt2?pt1:pt2)<<endl;
}
