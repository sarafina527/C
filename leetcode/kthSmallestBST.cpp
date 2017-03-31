/**Kth Smallest Element in a BST
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *  O(height of BST).
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int curth =0;
        return kthSmallest(root,k,curth);
    }
    int kthSmallest(TreeNode* root, int k,int &curth) {
    	if(!root) return;
        else{
            kthSmallest(root->left,k,curth);
            curth++;
            if(curth == k)
                return root->val;
            kthSmallest(root->right,k,curth);
        }
        return -1;
    }
};