//263. Ugly Number
//tag: Math
//问题描述：丑陋数字是正数，其主要因素仅包括2，3，5。
//思路：1.1是第一个丑数
//		2.若x是丑数，则2x,3x,5x是丑数，可用递归实现
//		3.考虑base case 是num为0和1，0不是丑数，1是丑数；递归式 num/5 num/3 num/2
class Solution {
public:
    bool isUgly(int num) {
        if(num==0) return false;
    	if(num==1) return true;
        else if(num%5==0)
        	return isUgly(num/5);
        else if(num%3==0)
        	return isUgly(num/3);
        else if(num%2==0)
        	return isUgly(num/2);
        else
        	return false;
    }
};