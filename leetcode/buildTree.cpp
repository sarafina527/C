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
    	TreeNode* root =  buildTreei(inorder,postorder,0,0,postorder.size()); 	
        
    	return root;
    }
    TreeNode* buildTreei(vector<int>& inorder, vector<int>& postorder,int ip,int pp,int size) {
        if(size<1) return NULL;
        int rootkey = postorder[pp+size-1];
        TreeNode* root = new TreeNode(rootkey);
    	if(size==1) return root;	
    	
    	int i;
        for(i=ip;i<ip+size&&inorder[i]!=rootkey;i++);//在中序序列中找到根，根据根所在位置，分割左右子树序列

        root->left = buildTreei(inorder,postorder,ip,pp,i-ip);
    	root->right = buildTreei(inorder,postorder,i+1,pp-ip+i,ip+size-i-1);//根据最后来倒推右子树的开始下标，pp+size-1-(ip+size-i-1),总后序序列的最后减去右子树大小
    	return root;

    }
};