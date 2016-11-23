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
    ListNode* swapPairs(ListNode* head) {
    	if(!head||!head->next) return head;
    	ListNode *p1 = head,*p2 = head->next;
    	do{
    		int tmp = p1->val;
    		p1->val = p2->val;
    		p2->val = tmp;
    		if(p2&&p2->next){
    			p1=  p1->next->next;
    			p2 = p2->next->next;
    		}else{
    			break;
    		}   		
    	}while(p2);
    	return head;        
    }
};