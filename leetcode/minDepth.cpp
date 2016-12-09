/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **BFS//根到叶子的最短路径
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return dfs(root,1);
    }
    int dfs(TreeNode* root,int d){//传入深度参数
        if(!root->right&&!root->left){//是叶子节点,回退
            return d;
        }else if(!root->right){//只有一个孩子，非叶子
            return dfs(root->left,d+1);
        }else if(!root->left){
            return dfs(root->right,d+1);
        }else{
            int dleft = dfs(root->left,d+1);
            int dright = dfs(root->right,d+1);
            return dleft<dright?dleft:dright;
        }
    }
};