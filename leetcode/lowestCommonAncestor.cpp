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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	TreeNode* lca;
        if(!root) return NULL;
        if(!p) return q;
        if(!q) return p;
        while((p->val<root->val&&q->val<root->val)||(p->val>root->val&&q->val>root->val)){
        	if(p->val<root->val&&q->val<root->val){
        		root = root->left;
        	}else{
        		root = root->right;
        	}
        }
        return root;
    }
};