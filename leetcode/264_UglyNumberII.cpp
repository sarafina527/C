//264. Ugly Number II
//tag: DP,Heap,Math
//问题描述：找到第n个丑数。
//思路：1.1是第一个丑数  类似筛法
//		2.若x是丑数，则2x,3x,5x是丑数，保持这样一个序列，每次取已有丑数序列中的最小数x，生成2x,3x,5x放入序列
//		3.保持这个序列可以用优先队列，最小的永远在前面
//		4.注意生成的数是否出现过，使用set实现,注意使用 long long ,int会溢出
class Solution {
public:
    int nthUglyNumber(int n) {
        assert(n>0);
    	int cof[3] = {2,3,5};
        priority_queue<long long,vector<long long>,greater<long long> > pq;
        set<long long> uniq;
        pq.push(1);
        uniq.insert(1);
        for(int i=1;i<n;i++){
        	long long min = pq.top();
        	pq.pop();
        	for(int j=0;j<3;j++){
        		long long tmp = min*cof[j];
        		if(!uniq.count(tmp)){//判断是否出现过
	        		pq.push(tmp);
	        		uniq.insert(tmp);
	        	}
        	}
        }
        return pq.top();
    }
};