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
    void recoverTree(TreeNode* root) {
        TreeNode* minp=NULL,*maxp=NULL,*lmis=NULL,*rmis=NULL;
        findMistake(root,minp,maxp,lmis,rmis);
        if(!lmis||!rmis) return;
        int tmp = lmis->val;
        lmis->val = rmis->val;
        rmis->val = tmp;
    }
    void findMistake(TreeNode* root,TreeNode* &minp,TreeNode* &maxp,TreeNode* &mis1,TreeNode* &mis2){
    	if(!root) return;
    	else if(!root->left&&!root->right){
    		minp = root;
    		maxp = root;
    	}else{
    		minp = maxp = root;
    		TreeNode* lmin=NULL,*lmax=NULL,*rmin=NULL,*rmax=NULL;
    		findMistake(root->left,lmin,lmax,mis1,mis2);
    		findMistake(root->right,rmin,rmax,mis1,mis2);
    		
			if(lmax&&lmax->val>root->val&&rmin&&rmin->val<root->val){
				maxp = mis1 = lmax;
				minp = mis2 = rmin;
			}else if(lmax&&lmax->val>root->val){
				maxp = mis1 = lmax;
			    mis2 = root;
    		}else if(rmin&&rmin->val<root->val){
				minp = mis2 = rmin;
				mis1 = root;
    		}
    		if(lmin&&minp->val>lmin->val)
    			minp = lmin;    		
    		if(rmax&&maxp->val<rmax->val)
    			maxp = rmax;
    	}
    }
};