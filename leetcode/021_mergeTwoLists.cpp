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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode* head = NULL;
    	if(l1==NULL){
    	    if(l2==NULL){
    	        return head;
    	    }else{
    	        head = new ListNode(l2->val);
        	    l2 = l2->next;
    	    }
    	}else if(l2==NULL||l1->val<=l2->val){
    	   
        	head = new ListNode(l1->val);
        	l1 = l1->next;
        }else{
            head = new ListNode(l2->val);
        	l2 = l2->next;
        }
        ListNode* p = head;
        while(l1!=NULL||l2!=NULL){
        	if(l1==NULL){
        		p->next = new ListNode(l2->val);
        		p = p->next;
        		l2 = l2->next;
        	}else if(l2==NULL){
        		p->next = new ListNode(l1->val);
        		p = p->next;
        		l1 = l1->next;
        	}else{
        		if(l1->val<=l2->val){
        			p->next = new ListNode(l1->val);
	        		p = p->next;
	        		l1 = l1->next;
        		}else{
        			p->next = new ListNode(l2->val);
	        		p = p->next;
	        		l2 = l2->next;
        		}
        	}
        }
        return head;

    }
};