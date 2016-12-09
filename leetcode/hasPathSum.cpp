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
    bool hasPathSum(TreeNode* root, int sum) {
    	if(!root) return false;
        bool ans = false;
        dfs(root,0,sum,ans);
        return ans;
    }
    void dfs(TreeNode* root,int pathsum,int sum,bool &ans){
    	if(!root) return;
    	pathsum+=root->val;//根到当前的路径上的和
    	if(!root->left&&!root->right){//叶子节点   		
    		if(pathsum==sum){
    			ans = true;
    		}
    	}else{
    		dfs(root->left,pathsum,sum,ans);
    		dfs(root->right,pathsum,sum,ans);
    	}
    }
};