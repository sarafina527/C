//390. Elimination Game
//问题描述:从左到右开始，然后删除第一个和奇数位数字的结尾。重复前面的步骤，但从右到左，1，3，5th，返回最后剩下的数。
//思路：分析：每次剩下的都是有序序列，且间隔相同，每一次操作间隔翻倍，剩下的数个数减半
//		1.保留这个区间首尾pair<first,second>和间隔offset
//		2.每次操作选择修改（从左到右）首部数字（fist+offset）或(右到左)末尾数字（second-offset），然后根据新间隔和剩余数目求出另一个
//		3.直到剩余一个数
class Solution {
public:
    int lastRemaining(int n) {
        assert(n>0);
    	pair<int,int> range = make_pair(1,n);
    	int offset = 1;
    	int leftnum = n;
    	bool left = 1;
    	while(leftnum>1){
    		if(left){//从左边，易于求区间左端点
    			range.first = range.first+offset;
    			leftnum /= 2;
    			offset *= 2;
    			range.second = (leftnum-1)*offset+range.first;
    			left = 0;
    		}else{//求右端点，推左端点
    			range.second = range.second - offset;
    			leftnum /=2;
    			offset *=2;
    			range.first = range.second - (leftnum-1)*offset;
    			left = 1;
    		}
    	}
    	return range.first;
    }
};