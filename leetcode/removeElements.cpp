/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        if(head->val == val){//特殊情况删除头
        	ListNode* tmp = head;
        	head = head->next;
        	free(tmp);
        	return head;
        }else{
        	ListNode* pre;
	        for(pre=head;pre->next&&;pre=pre->next){
	        	if(pre->next->val==val){
	        		ListNode* tmp = pre->next;
		        	pre->next = tmp->next;
		        	free(tmp);
	        	}
	        }
        }        
        return head;
    }
};