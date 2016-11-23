/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *先序遍历的演变
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans = vector<string>();
        if(!root) return ans;
        string str = string();
        Preorder(root,str,ans);
        return ans;
    }
    //str不能传引用，因为返回时，str需要时当前结点的路径
    void Preorder(TreeNode* r,string str,vector<string> &ans){
    	if(r){
    		string temp = to_string(r->val);
    		str.append(temp);
    		str.append("->"); 
    		if(!r->left&&!r->right){
    			int len = str.size()-2;
	    		ans.push_back(str.substr(0,len));
	    		str.assign("");
	 			return;
    		} 		
    		
    		Preorder(r->left,str,ans);
    		Preorder(r->right,str,ans);

    	}else{    		
    		return;
    	}
    }
};