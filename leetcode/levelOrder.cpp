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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans = vector<vector<int>>();
        queue<TreeNode*> q = queue<TreeNode*>();
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
        	vector<TreeNode*> curl = vector<TreeNode*>();
        	vector<int> subans = vector<int>();
        	while(!q.empty()){
        		TreeNode* t = q.front();
        		q.pop();
        		curl.push_back(t);
        		subans.push_back(t->val);
        	}
        	ans.push_back(subans);
        	for(int i=0;i<curl.size();i++){
        		if(curl[i]->left){
        			q.push(curl[i]->left);
        		}
        		if(curl[i]->right){
        			q.push(curl[i]->right);
        		}
        	}
        }
        return ans;
    }
};