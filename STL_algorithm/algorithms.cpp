#include <algorithm>
#include <numeric>//计算方面的算法
#include <iostream>
using namespace std;

bool CompareStringLength(string one, string two)
{
	return one.length() < two.length();
}
int main(){
	set<int> mySet;
	//1.累计函数在numeric头文件，前两个是范围参数，第三个是初始值，第四个是和函数
	accumulate(mySet.begin(), mySet.end(), 0);
	//2.上下界函数，下界返回>=42的迭代器，上界类似
	accumulate(mySet.lower_bound(42),mySet.upper_bound(137), 0);

	//reorder，容器中元素顺序的改变
	vector<int> myVector;
	vector<string> mystrv;
	//3.升序排序，sort不能用于map和set等有序容器，默认使用<运算符比较，也可指明比较函数（类似< 返回bool值而不是int值）
	sort(myVector.begin(), myVector.end());
	//4.即使有了默认的<函数，也可以重写cmp函数，实现不同的功能不同目的，cmp参数传值或者传指向const的引用
	sort(mystrv.begin(), mystrv.end(), CompareStringLength);
	//5.乱序，也只用纯如随机索引的迭代器，不能搅乱set和map
	random_shuffle(myVector.begin(), myVector.end());
	//6.rotate旋转，想环一样旋转(0, 1, 2, 3, 4, 5)-》(2, 3, 4, 5, 0, 1).参数begin, middle, end.
	rotate(v.begin(), v.begin() + 2, v.end());//中间的参数是新的begin

	//search
	//7.查找 线性搜索，但是像map、set这种有find成员函数的容器避免使用算法中的find，效率上差很多
	if(find(myVector.begin(), myVector.end(), 137) != myVector.end()){
		//do sth
	}

	//2.二分查找 仅当容器是有序的
	/* Assume myVector is sorted. */
	if(binary_search(myVector.begin(), myVector.end(), 137))
	{ /* ... Found 137 ... */ }


}
