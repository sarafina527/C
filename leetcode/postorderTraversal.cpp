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
    vector<int> postorderTraversal(TreeNode* root) {
    	vector<int> ans = vector<int>();
    	stack<TreeNode*> stk = stack<TreeNode*>();//用于记录待下一步遍历的节点
    	stack<TreeNode*> rev = stack<TreeNode*>();//用于逆序输出
    	TreeNode* t = root;
    	while(t||!stk.empty()){
    		while(t){
    			stk.push(t);
    			rev.push(t);
    			t = t->right;
    		}
    		if(!stk.empty()){
    			t = stk.top();
    			stk.pop();
    			t = t->left;
    		}
    	}
    	while(!rev.empty()){
    		t = rev.top();
    		rev.pop();
    		ans.push_back(t->val);
    	}
     	return ans;   
    }
};