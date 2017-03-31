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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int alen=0,blen=0,offset;
        ListNode* it = headA,*llist,*shlist,*ans=NULL;
        while(it){
            alen++;
            it = it->next;
        }
        it = headB;
        while(it){
            blen++;
            it = it->next;
        }
        if(alen>=blen){
            llist = headA;
            shlist = headB;
            offset = alen - blen;
        }else{
            llist = headB;
            shlist = headA;
            offset = blen - alen;
        }
        for(int i=0;i<offset;i++)
            llist = llist->next;
        if(listEqual(llist,shlist,ans))
            return llist;
        else
            return ans;

    }
    bool listEqual(ListNode *headA,ListNode* headB,ListNode* &target){
        if(!headA&&!headB)
            return true;
        else{
            bool nexteq = listEqual(headA->next,headB->next,target);
            if(nexteq&&headA!=headB){
                target = headA->next;
                return false;
            }else if(nexteq)
                return true;
            else
                return false;
        }
    }
};