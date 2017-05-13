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
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* newroot = copy(root);
        int sofar = 0;
        convertBST(newroot,sofar);
        return newroot;
    }
    void convertBST(TreeNode* root,int &sofar){
    	if(!root) return;
    	else{
    		convertBST(root->right,sofar);
    		sofar += root->val;
    		root->val = sofar;
    		
    		cout<<root->val<<" "<<sofar<<" "<<newroot->val<<endl;
    		convertBST(root->left,sofar);
    	}
    }
    TreeNode* copy(TreeNode* root){
    	if(!root) return NULL;
    	else{
    		TreeNode* newroot = new TreeNode(root->val);
    		newroot->left = copy(root->left);
    		newroot->right = copy(root->right);
    		return newroot;
    	}
    }
};