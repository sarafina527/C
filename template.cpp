#include <iostream>
#include <vector>
using namespace std;

template <typename Type>
void Swap(Type & one, Type & two)
{
	Type tmp = one;
	one = two;
	two = tmp;
}

template <typename T>
void PrintVector(vector<T> &v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}
template <typename Type>
int operatorCmp(Type a, Type b){
	if(a<b) return -1;
	else if(a>b) return 1;
	else return 0;
}
template <typename Type>
void Sort(vector<Type> &v, int (cmp)(Type, Type)=operatorCmp)
{
	for (int i = 0; i < v.size() - 1; i++) {
		int minIndex = i;
		for (int j = i+1; j < v.size(); j++) {
			if (cmp(v[j], v[minIndex])<0)
				minIndex = j;
		}
		Swap(v[i], v[minIndex]);
	}
}

int main(){
	int a=5,b=9;
	Swap(a,b);
	cout<<a<<" "<<b<<endl;
	
	string astr="a",bstr="b";
	Swap(astr,bstr);
	cout<<astr<<" "<<bstr<<endl;
	
	vector<int> vec(10,3);
	vec[9] = 0;
	vec[6] = 6;
	
	PrintVector(vec);
	Sort(vec);
	PrintVector(vec);
}
