/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *超时
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        int curh = 0,hleaves = 0;
        int h =lh = lheight(root),rh = rheight(root),l=0;
        while(lh!=rh){
        	l++;
        	lh = lheight(root->left);
        	rh = lheight(root->right);
        	if(lh!=rh){//出现在左半边是
        		continue;
        	}else{//右半边分层
        		lh = lheight(root->right);
        		rh = rheight(root->right);
        		hleaves += 1<<(h-1-l);
        	}
        }
        int ans = (1<<h)-1+hleaves;
        return ans;
    }
    int lheight(TreeNode* root){
    	int h = -1;
    	while(root){
    		h++;
    		root = root->left;
    	}
    	return h;
    }
    int rheight(TreeNode* root){
    	int h=-1;
    	while(root){
    		h++;
    		root = root->right;
    	}
    }
};