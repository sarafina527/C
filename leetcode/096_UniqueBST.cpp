//96. Unique Binary Search Trees
//tag: Tree ,DP dynamic programming
//问题描述：给定整数n，生成所有不重复的BST，返回所有的不同BST数目
//思路：1.递归，options有(high-low+1)个选择 每次选取区间[low,high]中的i，然后分成[low,i-1]和[i+1,high]两个区间递归生成左右子树的所有可能
//      2.根据生成的左右子树的可能数，相乘得到以i为根的所有可能
//      3.base case 是low>high只有一种可能，即空树；low==high也仅有一种可能即单节点树
class Solution {
public:
    int numTrees(int n) {
    	vector<int> book(n,-1);//标记连续i个数二叉树个数
        return numTrees(1,n,book);
    }
    int numTrees(int low,int high,vector<int>& book){
    	if(low==high)
    		return 1;
    	else if(low+1==high)
    		return 2;
    	else{
    		int ans = 0;
    		for(int i=low;i<=high;i++){
    			int leftnums=1,rightnums=1;
    			if(i-1>=low){
    				if(book[i-low]!=-1)
    					leftnums = book[i-low];
    				else{
    					leftnums = numTrees(low,i-1,book);
    					book[i-low] = leftnums;
    				}
    			}	
    			if(high>=i+1){
    				if(book[high-i]!=-1)
    					rightnums = book[high-i];
    				else{
    					rightnums = numTrees(i+1,high,book);
    					book[high-i] = rightnums;
    				}
    			}
    			ans+=leftnums*rightnums;
    		}
    		return ans;
    	}
    }
};