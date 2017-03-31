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
        TreeNode* pre = NULL;
        vector<int> ans;
        int prec=0,ansc=0;
        findMode(root,pre,prec,ans,ansc);
        if(prec>ansc){
            ans.clear();
            ans.push_back(pre->val);
            ansc = prec;
        }else if(prec==ansc&&pre){
            ans.push_back(pre->val);
        }
        return ans;
    }
    void findMode(TreeNode* root,TreeNode* &pre,int &prec,vector<int> &ans,int &ansc) {
        if(!root) return;
        findMode(root->left,pre,prec,ans,ansc);
        if(!pre){
            pre = root;
            prec = 1;
        }else if(root->val==pre->val){
            pre = root;
            prec++;
        }else if(root->val!=pre->val){
            if(prec>ansc){
                ans.clear();
                ans.push_back(pre->val);
                ansc = prec;
            }else if(prec==ansc){
                ans.push_back(pre->val);
            }
            pre = root;
            prec= 1;
        }
        findMode(root->right,pre,prec,ans,ansc);
    }
};