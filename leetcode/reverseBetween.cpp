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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i=1;
        ListNode* pre = head,*subhead,*subtail;
        for(;i<m-1;i++)
        	pre = pre->next;//前段的最后一个
        subhead = m>1?pre->next:head;
        subtail = subhead;
        ListNode* p = pre->next;
        for(i=m;i<=n;i++){
        	ListNode* next = p->next;
        	p->next = subhead;
        	subhead = p;
        	p = next;
        }
        if(m>1)
        	pre->next = subhead;
        else
        	head = subhead;
        if(subtail)
        	subtail->next = p;
        return head;
    }
};