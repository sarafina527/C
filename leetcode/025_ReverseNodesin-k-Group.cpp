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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* fast=head,*slow=head;
        int i=1;
        for(;i<k&&fast&&fast->next;i++)
        	fast = fast->next;
        if(i<k)//不足k个
        	return head;
        else{
        	ListNode *behind = fast->next;
        	head = reverseKGroup(behind,k);

        	while(slow!=fast){
        		ListNode *next = slow->next;
        		slow->next = head;
        		head = slow;
        		slow = next;
        	}
        	fast->next = head;
        	head = fast;
        	return head;
        }
    }
};