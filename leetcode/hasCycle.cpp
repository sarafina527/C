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
    bool hasCycle(ListNode *head) {
        ListNode *p1=head,*p2=head;
        do{
        	if(!p2||!p2->next){
        		return false;
        	}
        	p1 = p1->next;
        	p2 = p2->next->next;
        }while(p1!=p2);
        return true;
    }
};