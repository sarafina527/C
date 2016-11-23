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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	vector<vector<int>> ans = vector<vector<int>>();
    	if(!root) return ans;

    	queue<TreeNode*> q = queue<TreeNode*>();
    	stack<vector<int>> s = stack<vector<int>>();
    	vector<int> subans = vector<int>();
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
        	s.push(subans);
        	for(int i=0;i<curl.size();i++){
        		if(curl[i]->left){
        			q.push(curl[i]->left);
        		}
        		if(curl[i]->right){
        			q.push(curl[i]->right);
        		}
        	}
        }
        while(!s.empty()){
        	subans = s.top();
        	s.pop();
        	ans.push_back(subans);
        }
        return ans;
        
    }
};