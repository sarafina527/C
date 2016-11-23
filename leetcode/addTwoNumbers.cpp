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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        int c = 0;
        ListNode* p = NULL;
        if(l1==NULL&&l2==NULL){
        	head = NULL;
        }else if(l1==NULL){
        	head = new ListNode(l2->val);
        }else if(l2==NULL){
        	head = new ListNode(l1->val);
        }else{
        	int d = (l1->val+l2->val+c)%10;
			c = (l1->val+l2->val+c)/10;
			head = new ListNode(d);
			l1 = l1->next;
			l2 = l2->next;
        }
        p = head;       
    	while(l1!=NULL||l2!=NULL){
    		if(l1==NULL){
    			int d = (l2->val+c)%10;
    			c = (l2->val+c)/10;
    			p->next = new ListNode(d);
    			p = p->next;
    			l2 = l2->next;
    		}else if(l2==NULL){
    			int d = (l1->val+c)%10;
    			c = (l1->val+c)/10;
    			p->next = new ListNode(d);
    			p = p->next;
    			l1 = l1->next;
    		}else{
    			int d = (l1->val+l2->val+c)%10;
    			c = (l1->val+l2->val+c)/10;
    			p->next = new ListNode(d);
    			p = p->next;
    			l1 = l1->next;
    			l2 = l2->next;
    		}
    	}
    	if(c){
    		p->next = new ListNode(c);
    	}
    	return head;
        
    }
};