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
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *fast = head,*slow = head,*behead=NULL,*p;
        while(fast&&fast->next){
        	fast = fast->next->next;
            slow = slow->next;
        }
        p = slow->next;
        slow->next = NULL;
        while(p){//reverse second half
        	ListNode* next = p->next;
        	p->next = behead;
        	behead = p;
        	p = next;
        }
        ListNode *preit=head,*beit=behead;
        while(preit&&beit){
        	ListNode* prenext = preit->next;
        	preit->next = beit;
        	ListNode* benext = beit->next;
        	beit->next = prenext;
        	preit = prenext;
        	beit = benext;
        }

    }
};