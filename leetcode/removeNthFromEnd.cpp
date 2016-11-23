/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *思路是使用两个指针，两个指针相差n位，当第一个指针到达尾时，第二个指针到达n
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tail=head,*nt=new ListNode(0);
        int cnt=0;
        while(tail){
        	tail = tail->next;
        	if(cnt==n-1){
        		nt->next = head;
        	}else if(cnt>=n){
        		nt = nt->next;
        	}
        	cnt++;
        }
        if(!nt){
        	ListNode* tmp = nt->next;//待删除的节点
	        nt->next = tmp->next;
	        if(tmp==head){        	
	        	head = nt->next;//删除头节点更新头
	        }
	        free(tmp);
        }       
        return head;
    }
};