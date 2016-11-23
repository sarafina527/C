/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 *层次遍历的演变
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q = queue<TreeLinkNode*>();
        if(!root){
        	return;
        }
        q.push(root);
        while(!q.empty()){
        	vector<TreeLinkNode*> curlevel = vector<TreeLinkNode*>();
        	while(!q.empty()){
        		TreeLinkNode* t = q.front();
        		q.pop();
        		curlevel.push_back(t);
        	}
        	curlevel.push_back(NULL);
        	for(int i=0;i<curlevel.size()-1;i++){
        		curlevel[i]->next = curlevel[i+1];
        		if(curlevel[i]->left){
        			q.push(curlevel[i]->left);
        		}
        		if(curlevel[i]->right){
        			q.push(curlevel[i]->right);
        		}
        	}        	
        }

    }
};