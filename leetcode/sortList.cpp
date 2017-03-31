//148. Sort List
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
    ListNode* sortList(ListNode* head) {
        quicksort(head,NULL);
        return head;
    }
    void quicksort(ListNode* head,ListNode* tail){
        if(!head||head==tail||head->next == tail)
            return;
        else{
            ListNode* pivot = patition(head,tail);
            if(head&&head!=pivot&&head->next!=pivot)
                quicksort(head,pivot);
            if(pivot&&pivot->next&&pivot->next!=tail&&pivot->next->next!=tail)
                quicksort(pivot->next,tail);
        }
    }
    ListNode* patition(ListNode* head,ListNode* tail){
        if(!head||head==tail||head->next == tail)//当表空或者仅有一个元素
            return head;
        else{
            ListNode* i = head;
            ListNode* j = head->next;
            for(;j!=tail;j=j->next){
                if(j->val<=head->val){
                    i = i->next;
                    if(i!=j)
                        Swap(i,j);
                }
            }
            Swap(head,i);
            return i;
        }
    }
    void Swap(ListNode* p,ListNode* q){
        int tmp = p->val;
        p->val = q->val;
        q->val = tmp;
    }
};