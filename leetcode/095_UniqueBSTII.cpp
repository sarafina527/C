//95. Unique Binary Search Trees II
//tag: Tree ,DP dynamic programming
//问题描述：给定一个整数n，生成所有不重复结构的BST（二叉搜索树），存储值1到n
//思路：1.递归，options有(high-low+1)个选择 每次选取区间[low,high]中的i，然后分成[low,i-1]和[i+1,high]两个区间递归生成左右子树的所有可能
//		2.根据生成的左右子树的可能数，相乘得到以i为根的所有可能
//		3.base case 是low>high只有一种可能，即空树；low==high也仅有一种可能即单节点树
//		4.最后全都压入ans中
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n<1) return vector<TreeNode*>();
        map<pair<int,int>,vector<TreeNode*> > book;//用于保存重叠子结构的结果
        return generateTrees(1,n,book);
    }
    vector<TreeNode*> generateTrees(int low,int high,map<pair<int,int>,vector<TreeNode*> >& book){
    	if(low>high) return vector<TreeNode*>(1,NULL);    	
    	if(low==high){
    		TreeNode* root = new TreeNode(low);
    		return vector<TreeNode*>(1,root);
    	}else{
    		pair<int,int> tmp = make_pair(low,high);
    		vector<TreeNode*> ans;
    		for(int i=low;i<=high;i++){
    			vector<TreeNode*> lTree,rTree;//保存左右子树
    			pair<int,int> ltmp = make_pair(low,i-1);
    			pair<int,int> rtmp = make_pair(i+1,high);
    			//生成所有左子树
				if(book.find(ltmp)!=book.end())
					lTree = book[ltmp];
				else{
					lTree = generateTrees(low,i-1,book);
					book[ltmp] = lTree;
				}
				//生成所有右子树
				if(book.find(rtmp)!=book.end())
					rTree = book[rtmp];
				else{
					rTree = generateTrees(i+1,high,book);
					book[rtmp] = rTree;
				}
				//整合进ans
    			int lsize = lTree.size(),rsize = rTree.size();
    			for(int l=0;l<lsize;l++){
    				for(int r=0;r<rsize;r++){
    					TreeNode* tmp = new TreeNode(i);//生成每一种树
    					tmp->left = lTree[l];
    					tmp->right = rTree[r];
    					ans.push_back(tmp);
    				}
    			}
    		}
    		book[tmp] = ans;
    		return ans;
    	}
    }
};