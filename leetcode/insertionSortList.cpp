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
    ListNode* insertionSortList(ListNode* head) {
    	if(!head||!head->next) return head;
        ListNode* newhead = NULL,*p=NULL,*pre = new ListNode(INT_MIN),*mp =NULL,*mpre;
        ListNode* nilh = pre;
        nilh->next = head;//加入哨兵
        int max = INT_MIN;
        while(head){
        	pre = nilh;//前后指针查找，相差一位
        	p = head;
        	max = INT_MIN;
        	while(p){
        		if(max<=p->val){
        			max = p->val;
        			mpre = pre;
        			mp = p;
        		}
        		pre = pre->next;
        		p = p->next;
        	}
        	mpre->next = mp->next;
        	if(mp==head){
        		head = mp->next;
        	}
        	mp->next = newhead;
        	newhead = mp;      	
        }
        free(nilh);
        return newhead;
    }
};