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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pseq;
        vector<int> pd;
        vector<int> qseq;
        vector<int> qd;
        inorder(p,pseq,pd,0);
        inorder(q,qseq,qd,0);
        if(pseq.size()!=qseq.size()){
        	return false;
        }else{
        	for(int i=0;i<pseq.size();i++){
        		if(pseq[i]!=qseq[i]||pd[i]!=qd[i]){
        			return false;
        		}
        	}
        }
        return true;
    }
    void inorder(TreeNode* root,vector<int>& seq,vector<int>& dv,int d){
    	if(!root) return;
    	inorder(root->left,seq,dv,d+1);
    	seq.push_back(root->val);
    	dv.push_back(d);
    	inorder(root->right,seq,dv,d+1);
    }
};