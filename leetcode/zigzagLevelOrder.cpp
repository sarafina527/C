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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int>> ans; 
        queue<pair<TreeNode*,int>> nodesbuf;
        if(root)
            nodesbuf.push(make_pair(root,0));

        while(!nodesbuf.empty()){
        	pair<TreeNode*,int> cur = nodesbuf.front();
        	int curlevel = cur.second;
        	vector<int> tmp;
        	if(curlevel%2){
        		stack<TreeNode*> curlevelnodes;
        		while(!nodesbuf.empty()&&nodesbuf.front().second==curlevel){
        			cur = nodesbuf.front();
        			if(cur.first->left)
	        			nodesbuf.push(make_pair(cur.first->left,curlevel+1));
	        		if(cur.first->right)
	        			nodesbuf.push(make_pair(cur.first->right,curlevel+1));
        			curlevelnodes.push(cur.first);
        			nodesbuf.pop();
        		}
        		while(!curlevelnodes.empty()){
        			tmp.push_back(curlevelnodes.top()->val);
        			curlevelnodes.pop();
        		}
        	}else{
        		while(!nodesbuf.empty()&&nodesbuf.front().second==curlevel){
        			cur = nodesbuf.front();
        			tmp.push_back(cur.first->val);
        			if(cur.first->left)
	        			nodesbuf.push(make_pair(cur.first->left,curlevel+1));
	        		if(cur.first->right)
	        			nodesbuf.push(make_pair(cur.first->right,curlevel+1));
        			nodesbuf.pop();
        		}
        	}
        	ans.push_back(tmp);
        }
        return ans;
    }
};