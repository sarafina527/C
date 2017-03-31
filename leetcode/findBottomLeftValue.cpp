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
    int findBottomLeftValue(TreeNode* root) {
        assert(root != NULL); 
        vector<int> lefts;
        findBottomLeftValue(root,0,lefts);
        return lefts.back();
    }
    void findBottomLeftValue(TreeNode* root,int level,vector<int>& lefts){
    	if(!root) return;
    	if(level>=lefts.size()){
    		lefts.push_back(root->val);
    	}
    	findBottomLeftValue(root->left,level+1,lefts);
    	findBottomLeftValue(root->right,level+1,lefts);
    }
};