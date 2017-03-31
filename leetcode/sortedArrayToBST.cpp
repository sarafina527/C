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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = sortedArrayToBST(nums,0,nums.size()-1);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums,int p,int q){
    	TreeNode* root;
    	if(p>q)
    		return NULL;
    	if(p==q){
    		root = new TreeNode(nums[p]);
    		return root;
    	}
    	else{
    		int mid = (p+q)%2?(p+q)/2+1:(p+q)/2;
    		root = new TreeNode(nums[mid]);
    		root->left = sortedArrayToBST(nums,p,mid-1);
    		root->right = sortedArrayToBST(nums,mid+1,q);
    		return root;
    	}
    }
};