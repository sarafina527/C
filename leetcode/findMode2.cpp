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
    vector<int> findMode(TreeNode* root) {
    	vector<int> ans;
        int pren = -1;//qian yige shu
        int maxc = 0;//max cishu
        int curc = 0;//dangqian cishu
        trace(root,pren,maxc,ans,curc);
        return vector<int>(1,maxn->val);
    }
    void trace(TreeNode* root,int &pren,int& maxc,vector<int> &ans,int &curc){
    	if(!root){
    		return;
    	}
    	trace(root->left,pren,maxc,maxn,curc);
    	if(!maxc){
			pren = root;
			maxc = 1;
			ans.push(root->val);
			curc = 1;
		}else{
			if(root->val==pren){
				curc++;
				if(curc>maxc){
					ans.clear();
					ans.push_back(root->val);
					maxc = curc;
				}else if(curc==maxc&&ans[ans.size()-1]!=root->val){
					ans.push_back(root->val);
				}
			}else{
				curc = 1;
				if(curc==maxc&&ans[ans.size()-1]!=root->val){
					ans.push_back(root->val);
				pren = root->val;
			}
		}
    	
		trace(root->right,pren,maxc,maxn,curc);
    }
};