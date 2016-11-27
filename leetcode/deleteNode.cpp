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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* x = BSTSearch(root,key);
        if(!x) return root;
        TreeNode* wd;
    	if(!x->left||!x->right){
    		wd = x;
    	}else{
    		wd = BST_min(x->right);
    	}
    	// cout<<wd->val<<endl;
    	TreeNode* newchild;
    	if(wd->left){
    		newchild = wd->left;
    	}else{
    		newchild = wd->right;
    	}
    	TreeNode* fa = BST_parent(root,wd);//应该找到待删除节点的父亲
    	
    	if(!fa){//若待删除的是根
    		root = newchild;
    	}else{
    		if(wd==fa->left){
    			fa->left = newchild;
    		}else{
    			fa->right = newchild;
    		}
    	}
    	if(wd!=x){
    		x->val = wd->val;
    	}
    	free(wd);
    	return root; 
    }
    TreeNode* BSTSearch(TreeNode* root,int x){
    	TreeNode* ans = NULL;
    	if(!root||root->val==x){
    		return root;
    	}
    	if(x<root->val){
    		return BSTSearch(root->left,x);
    	}else{
    		return BSTSearch(root->right,x);
    	}
    }
    TreeNode* BST_parent(TreeNode* root,TreeNode* x){
    	if(!root) return root;
    	TreeNode* fa;
    	while(root&&root!=x){
    		fa = root;
    		if(x->val<root->val){
    			root = root->left;
    		}else{
    			root = root->right;
    		}
    	}
    	if(root){
    		return fa;
    	}else{
    		return NULL;
    	}
    }
    TreeNode* BST_min(TreeNode* root){
    	if(!root) return root;
    	while(root->left){
    		root = root->left;
    	}
    	return root;
    }
};