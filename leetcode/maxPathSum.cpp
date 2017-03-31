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
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN,sum=0,psum=0;
        maxPathSum(root,maxsum,sum,psum);
        return maxsum;
    }
    void maxPathSum(TreeNode* root,int &maxsum,int &sum,int &pathsum){
    	if(!root) return;
    	else{
    		sum += root->val;
    		pathsum += root->val;
    		int leftsum = 0,leftmax = INT_MIN,lpsum=0;
    		maxPathSum(root->left,leftmax,leftsum,lpsum);
    		if(maxsum<leftmax)
    		    maxsum = leftmax;
    		int rightsum = 0,rightmax = INT_MIN,rpsum=0;
    		maxPathSum(root->right,rightmax,rightsum,rpsum);
    		if(maxsum<rightmax)
			    maxsum = rightmax;
			if(lpsum>0){
				sum += lpsum;
				if(lpsum>=rpsum)//若左边子树和小于0则抛弃
					pathsum += lpsum;
    		}
    		if(rpsum>0){
    			sum += rpsum;
    			if(rpsum>lpsum)
    				pathsum += rpsum;
    		}
    		if(maxsum<sum)
			    maxsum = sum;
    	}
    }
};