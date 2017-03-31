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
    bool isValidBST(TreeNode* root) {
        long long max=LLONG_MIN,min=LLONG_MAX;
        return isValidBST(root,max,min);
    }
    bool isValidBST(TreeNode* root,long long &max,long long &min){
    	if(!root)
        	return true;
        else if(!root->left&&!root->right){
        	if(root->val<min)
        		min = root->val;
        	if(root->val>max)
        		max = root->val;
        	return true;
        }
        else{
        	TreeNode* left = root->left;
        	TreeNode* right = root->right;
        	long long leftmax=max,rightmin=min,leftmin=min,rightmax=max;
        	if((left==NULL||left->val<root->val)&&(right==NULL||right->val>root->val)){
        		bool leftvalid = isValidBST(left,leftmax,leftmin);
        		bool rightvalid = isValidBST(right,rightmax,rightmin);
        		if(rightmax>max)
        		    max = rightmax;
        		if(leftmin<min)
        		    min = leftmin;
        		if(leftvalid&&rightvalid&&root->val>leftmax&&root->val<rightmin)
        			return true;
        	}
        	return false;
        }
    }
};