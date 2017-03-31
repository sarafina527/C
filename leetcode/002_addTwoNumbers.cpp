//2.Add Two Numbers
//tag：Linked List ，Math
//问题描述：非空链表表示非负整数，逆序存储，个位在头节点，返回和链表
//假设：没有前导0
//思路：模拟加法，从头节点（个位）开始相加进位，一直到耨个链结束，加上进位 优化：先转成等长，再弄，但会申请内存需要自己释放
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        int c = 0;
        ListNode* p = NULL;
        if(l1==NULL&&l2==NULL){
        	head = NULL;
        }else if(l1==NULL){
        	head = new ListNode(l2->val);
        }else if(l2==NULL){
        	head = new ListNode(l1->val);
        }else{
        	int d = (l1->val+l2->val+c)%10;
			c = (l1->val+l2->val+c)/10;
			head = new ListNode(d);
			l1 = l1->next;
			l2 = l2->next;
        }
        p = head;       
    	while(l1!=NULL||l2!=NULL){
    		if(l1==NULL){
    			int d = (l2->val+c)%10;
    			c = (l2->val+c)/10;
    			p->next = new ListNode(d);
    			p = p->next;
    			l2 = l2->next;
    		}else if(l2==NULL){
    			int d = (l1->val+c)%10;
    			c = (l1->val+c)/10;
    			p->next = new ListNode(d);
    			p = p->next;
    			l1 = l1->next;
    		}else{
    			int d = (l1->val+l2->val+c)%10;
    			c = (l1->val+l2->val+c)/10;
    			p->next = new ListNode(d);
    			p = p->next;
    			l1 = l1->next;
    			l2 = l2->next;
    		}
    	}
    	if(c){
    		p->next = new ListNode(c);
    	}
    	return head;
        
    }
};