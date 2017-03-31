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
        int maxc=0,curval,curcount;
        findMode(root,maxc,ans,curval,curcount);
        return ans;
    }
    void findMode(TreeNode* root,int& maxc,vector<int> &ans,int &curval,int &curcount){
        if(!root){
            maxc==0;
            return;
        }
        if(!root->left&&!root->right){
            curval = root->val;
            curcount = 1;
            ans.push_back(curval);
            maxc = 1;
        }
        else{
            int leftmaxc=0,rightmaxc=0,leftval,leftc,rightval,righc;
            vector<int> leftans,rightans;
            findMode(root->left,leftmaxc,leftans,leftval,leftc);
            findMode(root->right,rightmaxc,rightans,rightval,righc);
            curval = root->val;
            curcount = 1;
            if(leftmaxc>0&&curval==leftval)
                curcount += leftc;
            if(rightmaxc>0&&curval==rightval)
                curcount += righc;
            //merge left and right
            if(rightmaxc>leftmaxc){
                ans = rightans;
                maxc = rightmaxc;
            }else if(rightmaxc<leftmaxc){
                ans = leftans;
                maxc = leftmaxc;
            }else{//相等
                if(leftmaxc>0&&rightmaxc>0&&curcount<=leftmaxc){
                    maxc = leftmaxc;
                    ans.insert(ans.end(),leftans.begin(),leftans.end());
                    ans.insert(ans.end(),rightans.begin(),rightans.end());
                }else
                    maxc = 0;
            }
            cout<<"before: "<<curval<<" "<<curcount<<" "<<maxc<<endl;
            //compare with cur            
            if(curcount==maxc){
                ans.push_back(curval);
            }else if(curcount>leftmaxc){
                ans.clear();
                ans.push_back(curval);
                maxc = curcount;
            }
            cout<<"afterright: "<<curval<<" "<<curcount<<" "<<maxc<<endl;
        }
        cout<<"last: "<<curval<<" "<<curcount<<" "<<maxc<<endl;
    }
};