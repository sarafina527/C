//396. Rotate Function
//tag: Math
//问题描述：旋转A数组K位[0~n-1]后得到BK数组,一个加权函数F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1]，返回k取[0~n-1]不同值时F的最大值。
//思路：1.朴素思想是 每次求出旋转后数组 的加权和，进行对比得到最大值，可是这样是n2的复杂度
//		2.进一步的思想是，求出F(k+1)与F(k)的递推关系式，然后可以O（n）求出了
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if(A.size()==0) return 0;
    	long long ans = INT_MIN;
    	int n = A.size();
    	long long sum = Sum(A);
    	long long tmpsum = weightSum(A);
    	int lastindex = n-1;
        for(int i=1;i<=A.size()&&lastindex>=0;i++){
        	if(tmpsum>ans)
        		ans = tmpsum;
        	tmpsum = tmpsum - n*A[lastindex] +sum;//F(k+1)与F(k)的递推关系式
        	lastindex --;
        }
        return ans;
    }
    long long Sum(vector<int>&A){
    	long long ans = 0;
    	for(int i=0;i<A.size();i++)
    		ans += A[i];
    	return ans;
    }
    long long weightSum(vector<int> &A){
    	long long ans = 0;
    	for(int i=0;i<A.size();i++)
    		ans += i*A[i];
    	return ans;
    }
};