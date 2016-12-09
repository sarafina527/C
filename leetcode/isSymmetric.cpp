/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 树是否对称，关于根，左子树、右子树分别中序遍历看是否是逆序,附加层次序列
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if(!root) return true;
        vector<int> leftseq = vector<int>();
        vector<int> leftd = vector<int>();
        vector<int> rightseq = vector<int>();
        vector<int> rightd = vector<int>();
        lrinorder(root->left,leftseq,leftd,1);
        rlinorder(root->right,rightseq,rightd,1);
        if(leftseq.size()!=rightseq.size()){
        	return false;
        }else{
        	for(int i=0;i<leftseq.size();i++){
        		if(leftseq[i]!=rightseq[i]||leftd[i]!=rightd[i]){
        			return false;
        		}
        	}
        }
        return true;
    }
    void lrinorder(TreeNode* root,vector<int>& seq,vector<int>& leftd,int d){
    	if(!root) return;
    	lrinorder(root->left,seq,leftd,d+1);
    	seq.push_back(root->val);
    	leftd.push_back(d);
    	lrinorder(root->right,seq,leftd,d+1);
    }
    void rlinorder(TreeNode* root,vector<int>& seq,vector<int>& rightd,int d){
    	if(!root) return;
    	rlinorder(root->right,seq,rightd,d+1);
    	seq.push_back(root->val);
    	rightd.push_back(d);
    	rlinorder(root->left,seq,rightd,d+1);
    }
};