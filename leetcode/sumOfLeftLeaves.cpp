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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        sumOfLeftLeaves(root,0,ans);
        return ans;
    }
    void sumOfLeftLeaves(TreeNode* root,bool left,int &sum){
    	if(!root) return;
    	if(!root->left&&!root->right&&left) sum+=root->val;
    	else{
    		sumOfLeftLeaves(root->left,1,sum);
    		sumOfLeftLeaves(root->right,0,sum);
    	}
    }
};