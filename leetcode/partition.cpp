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
	ListNode* reverseList(ListNode* head){
	    ListNode* newhead=NULL;
	    while(head){
	        ListNode* tmp = head->next;//保存当前的下一个
	        head->next = newhead;//newhead 保存了已经反转的前面部分链表的头指针
	        newhead = head;
	        head = tmp;
	    }
	    return newhead;
	}
    ListNode* partition(ListNode* head, int x) {
        ListNode *lh=NULL,*rh=NULL;
        while(head){
        	ListNode* tmp = head->next;
        	if(head->val<x){        		
        		head->next = lh;
        		lh = head;
        		head = tmp;
        	}else{
        		head->next = rh;
        		rh = head;
        	}
        	head = tmp;//迭代
        }
        lh = reverseList(lh);
        rh = reverseList(rh);
        if(!lh){
        	return rh;
        }        
        ListNode* tail = lh;        
        while(tail&&tail->next){//找到左子链的尾
        	tail = tail->next;
        }
        tail->next = rh;
        return lh;
    }
};