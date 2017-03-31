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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool ctp=0,ctq = 0;
        return lowestCommonAncestor(root,p,ctp,q,ctq);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p,bool &ctp, TreeNode* q,bool &ctq) {
    	if(!root) return NULL;
    	else{
    		bool lctp=0,lctq=0,rctp=0,rctq=0;
    		TreeNode *tmp = lowestCommonAncestor(root->left,p,lctp,q,lctq);
    		if(tmp) return tmp;
	        tmp = lowestCommonAncestor(root->right,p,rctp,q,rctq);
	        if(tmp) return tmp;
	        ctp = root==p||lctp||rctp;
	        ctq = root==q||lctq||rctq;
	        //cout<<root->val<<root<<" "<<p<<" "<<q<<" "<<(root==p)<<" "<<(root==q)<<" "<<ctp<<" "<<ctq<<endl;
	        if(ctp&&ctq)
	        	return root;
	        else
	        	return NULL;
    	}
    }
};