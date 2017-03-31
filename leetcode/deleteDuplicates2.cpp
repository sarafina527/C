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
        ListNode* pre = head,*cur,*next,*tmp;
		while(head&&head->next&&head->val==head->next->val){//delete repeat head
			cur = head;
			next = head->next;
			while(next&&next->val==cur->val){
				tmp = next;
				next = next->next;
				delete tmp;
			}
			delete cur;
			head = next;
		}
    	pre = head;//第一个无重复的节点
    	while(pre&&pre->next&&pre->next->next){//需要判定后两个是否重复
    		cur = pre->next;
    		next = cur->next;
    		if(cur->val==next->val){
    			while(next&&next->val==cur->val){
    				tmp = next;
    				next = next->next;
    				delete tmp;
    			}
    			delete cur;	
    			pre->next = next;
    		}else{//当后两个不重复才能更新pre，pre不能是重复点
    			pre = pre->next;
    		}	
    	}
        
        return head;
    }
};