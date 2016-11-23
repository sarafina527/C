#include <iostream>
#include <vector>
using namespace std;
//选择排序的简化
class Solution {
public:
    int thirdMax(vector<int>& nums) {
    	int sortedf = nums.size()-1;//比较之后的元素是排序后的
    	vector<int> max = vector<int>();
        while(max.size()<3&&sortedf>=0){//找到第三大或者数组扫面结束
        	int curmaxi = 0;
        	for(int i=0;i<=sortedf;i++){
        		if(nums[i]>nums[curmaxi]){
        			curmaxi = i;
        		}
        	}
        	//找到当前 前面子数组的最大值
        	int tmp = nums[curmaxi];
        	nums[curmaxi] = nums[sortedf];
        	nums[sortedf] = tmp;
            sortedf--;
        	
        	if(max.empty()||tmp!=max[max.size()-1]){
        		max.push_back(tmp);
        	}
        }
        if(max.size()<3){
            return max[0];
        }else{
            return max[2];
        }        
    }
};
int main(){
	Solution sl = Solution();
	vector<int> v = vector<int>();
	v.push_back(3);v.push_back(2);v.push_back(1);
	sl.thirdMax(v);
}
