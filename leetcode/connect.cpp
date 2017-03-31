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
        if(!root) return;
        q.push(root);
        while(!q.empty()){//一层一层的遍历，每次队列中只有一层的节点
        	vector<TreeLinkNode*> curlevel//存放当前层
        	while(!q.empty()){//从队列中一次取出一层
        		TreeLinkNode* t = q.front();
        		q.pop();
        		curlevel.push_back(t);
        	}
        	curlevel.push_back(NULL);
        	for(int i=0;i<curlevel.size()-1;i++){
        		curlevel[i]->next = curlevel[i+1];//填充next域
        		if(curlevel[i]->left){//将下一层的节点放入队列中
        			q.push(curlevel[i]->left);
        		}
        		if(curlevel[i]->right){
        			q.push(curlevel[i]->right);
        		}
        	}        	
        }

    }
};