/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *思路是两两合并，两个指针首尾合并
 */
class Solution {
public:
    ListNode* merge2Lists(ListNode* a,ListNode*b){
        ListNode* ans=NULL,*t=NULL;
        if(!a) return b;
        if(!b) return a;
        while(a&&b){
            ListNode* mp = NULL;
            if(a->val<=b->val){
                mp = a;
                a = a->next;               
            }else{
                mp = b;
                b = b->next;
            }
            if(!ans){//将较小的添加到结果链表中
                t = ans = mp;
            }else{
                t->next = mp;
                t = mp;
            }
        }
        if(a){
            t->next = a;                      
        }else if(b){
            t->next = b;
        }
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int t=lists.size()-1;
        if(t<0) return NULL;
        while(t>0){
            for(int i=0;i<=t/2;i++){
                if(i!=t-i){
                    lists[i] = merge2Lists(lists[i],lists[t-i]);
                }
            }
            t = t/2;
        }        
        return lists[0];
    }
};