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
    int countNodes(TreeNode* root) {
        int h = height(root);
        int pre = (1<<h)-1;//除最后一层的节点个数
        int lastlc = 0,curl=0;
        TreeNode* lastleaf = root;//查找最后一层最后一个叶子
        while(lastleaf){//直到是叶子，因为非叶子节点必有左孩子
            if(!lastleaf->left){//已经是叶子
                lastlc++;
                break;
            }else if(!lastleaf->right){//如果没有右边孩子,左边
        		lastleaf = lastleaf->left;
        	}else{
        		int midh = curl+1+righth(lastleaf->left);
        		if(midh<h)
	        		lastleaf = lastleaf->left;//确定在左边，抛弃右边的
	        	else{//midh==h
	        		int midh2 = curl+1+height(lastleaf->right);
	        		if(midh2<h){//找到了
	        			lastlc += (1<<(h-curl-1));
		        		break;
	        		}else{
	        			lastleaf = lastleaf->right;
		        		lastlc += (1<<(h-curl-1));
	        		}
	        	}
        	}
        	curl++;
        }
        return lastlc+pre;
    }
    int height(TreeNode* root){
    	int h = 0;
    	while(root&&root->left){
    		h++;
    		root = root->left;
    	}
    	return h;
    }
    int righth(TreeNode* root){
    	int h=0;
    	while(root&&root->right){
    		h++;
    		root = root->right;
    	}
    	return h;
    }
};