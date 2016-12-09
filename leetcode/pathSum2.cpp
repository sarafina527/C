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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ans;
        vector<int> path;
        dfs(root,0,path,sum,ans);
        return ans;
    }
    void dfs(TreeNode* root,int pathsum,vector<int> path,int sum,vector<vector<int> > &ans){
    	if(!root) return;
    	pathsum+=root->val;//根到当前的路径上的和
    	path.push_back(root->val);
    	if(!root->left&&!root->right){//叶子节点   		
    		if(pathsum==sum){
    			ans.push_back(path);
    		}
    	}else{
    		dfs(root->left,pathsum,path,sum,ans);
    		dfs(root->right,pathsum,path,sum,ans);
    	}
    }
};