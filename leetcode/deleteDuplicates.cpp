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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = head;
        while(pre&&pre->next){
        	ListNode* cur = pre->next;
        	if(cur->val==pre->val){
        		pre->next = cur->next;
        		delete cur;
        	}else{
        		pre = cur;
        	}
        }
        return head;
    }
};