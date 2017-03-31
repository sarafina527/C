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
    vector<TreeNode*> generateTrees(int n) {
    	vector<TreeNode*> ans;
        ans = generateTrees(1,n);
    }
    vector<TreeNode*> generateTrees(int low,int high) {
    	vector<TreeNode*> ans;
    	if(low==high){
    		TreeNode* root = new TreeNode(low);
    		ans.push_back(root);
    	}else if(low+1==high){
    		TreeNode* root = new TreeNode(low);
    		TreeNode* right = new TreeNode(high);
    		root->right = right;
    		ans.push_back(root);
    		TreeNode* root2 = new TreeNode(high);
    		TreeNode* left = new TreeNode(low);
    		root2->left = left;
    		ans.push_back(root2);
    	}else{

    		for(int i=low;i<=high;i++){
    			TreeNode* root = new TreeNode(i);
    			if(i-1>=low){
    				
    				vector<TreeNode*> leftTree = generateTrees(low,i-1);
    				for(int i=0;i<leftTree.size();i++)
    				
    			}	
    			if(high>=i+1){
    				if(book[high-i]!=-1)
    					rightnums = book[high-i];
    				else{
    					rightnums = numTrees(i+1,high,book);
    					book[high-i] = rightnums;
    				}
    			}
    			ans+=leftnums*rightnums;
    		}
    		return ans;
    	}
        
    }
};