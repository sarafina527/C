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
    vector<int> largestValues(TreeNode* root) {
    	vector<int> ans;
        largestValues(root,0,ans);
        return ans;
    }
    void largestValues(TreeNode* root,int dep,vector<int> &lav) {
        if(!root) return;
        if(lav.size()<dep+1){
        	lav.push_back(root->val);
        }else if(lav[dep]<root->val){
        	lav[dep] = root->val;
        }
        largestValues(root->left,dep+1,lav);
        largestValues(root->right,dep+1,lav);
    }
};