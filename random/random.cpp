#include <random.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
bool RandomChance(double p) {
	return RandomReal(0, 1) < p;
}
int RandomInteger(int low, int high) {
	double d = double(rand()) / (double(RAND_MAX) + 1);
	int k = int(d * (high - low + 1));
	return low + k;
}
double RandomReal(double low, double high) {
	double d = double(rand()) / (double(RAND_MAX) + 1);
	return low + d * (high - low);
}

int main(){
	//1.初始 返回不大于RAND_MAX(依赖系统，2147483647)的非负数
	//伪随机,初始时会有个种子，然后第一次生成随机数是根据种子（黑盒）生成，而后面的随机数根据前一个随机数生成
	//由于种子初始值是常数，每次运行该段代码，都形成同一序列
	int rand();

	//2.为了出不同序列，设置不同种子，time函数是ctime库中的，获取内部系统时钟
	srand(int(time(NULL)));



}