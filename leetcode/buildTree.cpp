/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 思路，使用分治法，根据后序判断出根，则可分为左右子树
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	buildTreei(inorder,postorder,0,postorder.size()-1)
    	
        int i;
        for(i=0;i<inorder.size()&&inorder[i]!=rootkey;i++);
        vector<int> leftin = vector<int>();
    	vector<int> leftpo = vector<int>();
    	vector<int> rightin = vector<int>();
    	vector<int> rightpo = vector<int>();
    	for(int j=0;j<i;j++){
    		leftin.push_back(inorder[j]);
    		leftpo.push_back(postorder[j]);
    	}
    	for(int j=i;j<inorder.size()-1;j++){
    		rightpo.push_back(postorder[j]);
    		rightin.push_back(inorder[j+1]);
    	}
    	root->left = buildTree(leftin,leftpo);
    	root->right = buildTree(rightin,rightpo);
    	return root;
    }
    TreeNode* buildTreei(vector<int>& inorder, vector<int>& postorder,int sti,int stp,int size) {
    	if(st>end) return NULL;
    	int rootkey = postorder[end];
    	TreeNode* root = new TreeNode(rootkey);
    	if(st==end) return root;
    	int i;
        for(i=st;i<inorder.size()&&inorder[i]!=rootkey;i++);
        buildTreei(inorder,postorder,st,stp,i-st);
    	buildTreei(inorder,postorder,i+1,i,size-i+st-1);
    	

    }
};