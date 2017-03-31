/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *思路是比较k个链表头，选择最小的插入新表的头，更新选中的链表头，超时
 */
class Solution {
public:
    int getLen(ListNode* head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode *head,*minp,*ans=NULL,*t=NULL;
        int len = 0,size=0;
        for(int i=0;i<lists.size();i++){
            len+=getLen(lists[i]);
        }
        while(size<len){
        	int min = INT_MAX;
        	int mini = -1;
        	minp = NULL;
        	for(int i=0;i<lists.size();i++){
        		if(lists[i]&&lists[i]->val<=min){//当第i个链不空，且是当前最小时
        			min = lists[i]->val;
        			mini = i;
        			minp = lists[i];
        		}
        	}
            lists[mini] = minp->next;//删除
            if(ans){//插入到总表的尾
                t->next = minp;
                t = minp;
            }else{
                t = ans = minp;//头为空时，插到头部
            }
            size++; 
        }
        return ans;
    }
};