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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        sumNumbers(root,0,ans);
        return ans;
    }
    void sumNumbers(TreeNode* root,int parentsum,int &ans){
    	if(!root)
    		return;
    	else if(!root->left&&!root->right){//leaf
    		ans += parentsum*10+root->val;
    	}else{
    		sumNumbers(root->left,parentsum*10+root->val,ans);
    		sumNumbers(root->right,parentsum*10+root->val,ans);
    	}
    }
};