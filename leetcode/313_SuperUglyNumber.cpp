//313. Super Ugly Number
//tag: Heap,Math
//问题描述：找到第n个丑数。超时
//思路：1.1是第一个丑数  类似筛法
//		2.若x是丑数，给定素数列表中,则素数因子乘x是丑数，保持这样一个序列，每次取已有丑数序列中的最小数x，生成c*x放入序列
//		3.保持这个序列可以用优先队列，最小的永远在前面
//		4.注意生成的数是否出现过，使用set实现,注意使用 long long ,int会溢出
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        assert(n>0);
        priority_queue<long long,vector<long long>,greater<long long> > pq;
        set<long long> uniq;
        pq.push(1);
        uniq.insert(1);
        for(int i=1;i<n;i++){
        	long long min = pq.top();
        	pq.pop();
        	for(int j=0;j<primes.size();j++){
        		long long tmp = min*primes[j];
        		if(!uniq.count(tmp)){//判断是否出现过
	        		pq.push(tmp);
	        		uniq.insert(tmp);
	        	}
        	}
        }
        return pq.top();
    }
};