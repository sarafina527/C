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
	
    
    bool isPalindrome(ListNode* head) {
    	if(!head||!head->next) return true;
        ListNode *p1=head,*p2=head;//p2的速度是p1的两倍
        while(p2&&p2->next){
        	p1 = p1->next;
        	p2 = p2->next->next;
        }
        ListNode* mid = NULL;//翻转
        while(p1){
        	ListNode* tmp = p1->next;//保存当前的下一个
    		p1->next = mid;//newhead 保存了已经反转的前面部分链表的头指针
    		mid = p1;
    		p1 = tmp;
        }
        p2 = head;
        while(mid&&p2){
        	if(p2->val!=mid->val){
        		break;
        	}
        	p2 = p2->next;
        	mid = mid->next;
        }
        if(mid){
        	return false;
        }else{
        	return true;
        }        
    }
    
};