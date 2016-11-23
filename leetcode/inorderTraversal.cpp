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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans = vector<int>();
        stack<TreeNode*> s = stack<TreeNode*>();
        TreeNode* t = root;
        while(t||!s.empty()){
        	while(t){
        		s.push(t);
        		t = t->left;
        	}
        	if(!s.empty()){
        		t = s.top();
        		s.pop();
        		ans.push_back(t->val);
        		t = t->right;
        	}
        }
        return ans;
    }
};