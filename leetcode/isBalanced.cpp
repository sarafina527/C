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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalanced(root,depth);
    }
    bool isBalanced(TreeNode* root,int &depth) {
    	if(!root)
    		return true;
    	else{
    		depth++;
    		int ldepth = depth,rdepth = depth;
    		//cout<<root->val<<" "<<depth<<endl;
    		bool lflag,rflag;
    		lflag = isBalanced(root->left,ldepth);
	        rflag = isBalanced(root->right,rdepth);
	        depth = ldepth>rdepth?ldepth:rdepth;
	        //cout<<root->val<<" "<<ldepth<<" "<<rdepth<<endl;
	        int depthdiff = ldepth>rdepth?ldepth-rdepth:rdepth-ldepth;
	        if(lflag&&rflag&&depthdiff<=1)
	        	return true;
	        else
	        	return false;
    	}
        
    }
};