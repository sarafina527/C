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
    void flatten(TreeNode* root) {
    	if(!root)
    		return;
    	flatten(root->left);
    	flatten(root->right);
        TreeNode* r = root->right;
        TreeNode* p = root;
        if(root->left){//将平铺后的左子树放在树的右边，并将左边置空，并连接平铺右子树
        	p->right=root->left;
        	p->left = NULL;
        	while(p&&p->right)
        		p= p->right;
        }	
        p->right = r;
    }
};