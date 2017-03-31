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
    vector<int> findFrequentTreeSum(TreeNode* root) {
    	vector<int> ans;
    	int f = 0;
        map<int,int> sumcount;
        treeSum(root,sumcount);
        map<int,int>::iterator it;
        for(it=sumcount.begin();it!=sumcount.end();it++){
        	if(it->second>f){
        	    f = it->second;
        		ans.clear();
        		ans.push_back(it->first);
        	}else if(it->second == f)
        		ans.push_back(it->first);
        }
        return ans;

    }
    int treeSum(TreeNode* root,map<int,int> &sumcount){
    	if(!root) return 0;
    	int leftsum = treeSum(root->left,sumcount);
    	int rightsum = treeSum(root->right,sumcount);
    	int sum = leftsum+rightsum+root->val;
    	sumcount[sum]++;
    	return sum;
    }
};