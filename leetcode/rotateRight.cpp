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
    ListNode* rotateRight(ListNode* head, int k) {
    	int len = getLen(head);
    	k = k%len;
    	if(k==0) return head;
    	ListNode *ans;
        ListNode *fast = head;
        ListNode *slow = head;
        while(k&&fast){
        	if(!fast->next)
        		fast->next = head;
        	fast = fast->next;
        	k--;
        }
        while(fast&&fast->next){
        	fast = fast->next;
        	slow = slow->next;
        }
        if(fast&&slow){
           fast->next = head;
            ans = slow->next;
            slow->next = NULL; 
        }
        return ans;

    }
    int getLen(ListNode* head){
    	int ans = 0;
    	while(head){
    		ans++;
    		head = head->next;
    	}
    	return ans;
    }
};