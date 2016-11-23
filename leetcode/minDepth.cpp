/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **回溯法
 */
class Solution {
public:
    int minDepth(TreeNode* root) {    	

    	if(!root) return 0;
    	int mind = INT_MAX;
    	stack<TreeNode*> path = stack<TreeNode*>();//记录搜索的路径
    	TreeNode* t = root;
    	int d = 1;//当前深度
    	while(t||!path.empty()){
    		while(t){
    			path.push(t);
    			d++;//随着左边路径深入，深度逐步加深其实等于栈的长度
    			if(!t->left&&!t->right){//t为叶子则记录当前深度
    				if(d<mind){
    					mind = d;
    				}
    			}
    			t = t->left;
    			
    		}

    		if(!path.empty()){
    			t = path.top();//取当前节点的父亲，深度减
    			path.pop();
    			d--;    			
    			t = t->right;	
    		}   		
    	}    		
    	return mind;
    }
    
};