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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root =  buildTreei(preorder,inorder,0,0,preorder.size()); 	
        
    	return root;
    }
    TreeNode* buildTreei(vector<int>& preorder, vector<int>& inorder,int pp,int ip,int size) {
        if(size<1) return NULL;
        int rootkey = preorder[pp];
        TreeNode* root = new TreeNode(rootkey);
    	if(size==1) return root;	
    	
    	int i;
        for(i=ip;i<ip+size&&inorder[i]!=rootkey;i++);//在中序序列中找到根，根据根所在位置，分割左右子树序列

        root->left = buildTreei(preorder,inorder,pp+1,ip,i-ip);
    	root->right = buildTreei(preorder,inorder,pp-ip+i+1,i+1,ip+size-i-1);//根据最后来倒推右子树的开始下标，pp+size-1-(ip+size-i-1),总后序序列的最后减去右子树大小
    	return root;

    }
};