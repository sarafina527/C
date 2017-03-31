/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        while(p){
        	p = p->next;
        	len++;
        }
        TreeNode* root = generateVoidTree(len);
        fillNums(root,head);
        return root;
    }
    TreeNode* generateVoidTree(int num){
    	if(num<=0)
    		return NULL;
    	else if(num==1)
    	    return new TreeNode(0);
    	else{//depth>=1
    		int left = num,depth=-1;
	    	while(left>0){
	    		depth++;
	    		left -= 1<<depth;//减去一层的数量
	    	}
	    	int comtree = (1<<depth)-1;
	    	int lnum = comtree>>1,rnum = lnum;
	    	int lalenum = num - comtree;//最后一层的数量
	    	// int llhalf = 1<<(depth-1);//完全树做法
	    	// if(lastlevel>llhalf){
	    	// 	lnum += llhalf;
	    	// 	rnum = lastlevel - llhalf;
	    	// }else
	    	// 	lnum += lastlevel;
	    	int rlale = lalenum>>1;
	    	rnum += rlale;
	    	lnum += lalenum - rlale;
	    	TreeNode* root = new TreeNode(0);
	    	root->left = generateVoidTree(lnum);
	    	root->right = generateVoidTree(rnum);
	    	return root;
    	}
    }
    void fillNums(TreeNode* root,ListNode* &head){
    	if(!root)
    		return;
    	else{
    		fillNums(root->left,head);
    		root->val = head->val;
    		head = head->next;
    		fillNums(root->right,head);
    	}
    }
};