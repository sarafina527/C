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
    int diameterOfBinaryTree(TreeNode* root) {
        int longpath=0,maxdiam=0;
        longPathOfBT(root,longpath,maxdiam);
        return maxdiam;
    }
    void longPathOfBT(TreeNode* root,int &longpath,int &maxdiam){
    	if(!root){
    		longpath = -1;
    		return;
    	}
    	int lp=0,rp=0;
    	longPathOfBT(root->left,lp,maxdiam);
    	longPathOfBT(root->right,rp,maxdiam);
    	longpath = lp>=rp?lp+1:rp+1;
    	if(lp+rp+2>maxdiam)
    		maxdiam = lp+rp+2;
    }
};