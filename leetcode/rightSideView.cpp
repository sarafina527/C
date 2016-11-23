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
    vector<int> rightSideView(TreeNode* root) {
    	vector<int> ans = vector<int>();
    	vrlTraverse(root,ans,1);
        return ans;
    }
    void vrlTraverse(TreeNode* cur,vector<int> &ans,int depth){
        if(cur){
            if(ans.size()<depth){
                ans.push_back(cur->val);
            }
            vrlTraverse(cur->right,ans,depth+1);
            vrlTraverse(cur->left,ans,depth+1);
        }else{
            return;
        }
    }
};