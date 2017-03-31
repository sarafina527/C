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
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* oddpre=head,*fast=head,*evenHead,*evenpre;
        while(fast&&fast->next){
        	if(fast==head){
        		evenHead = fast->next;
        		evenpre = evenHead;
        	}else{
        		evenpre->next = fast->next;
        		evenpre = evenpre->next;
        	}
        	fast = fast->next->next;
        	if(fast!=NULL){
        		oddpre->next = fast;
        		oddpre = fast;
        	}
        }
        evenpre->next = NULL;
        oddpre->next = evenHead;
        return head;
    }
};