/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode*,RandomListNode*> src2new;
        return copyRandomList(head,src2new);
    }
    RandomListNode *copyRandomList(RandomListNode *head,map<RandomListNode*,RandomListNode*> &src2new){
        if(!head)
            return NULL;
        else{
            RandomListNode* newhead = src2new.find(head)!=src2new.end()?src2new[head]:new RandomListNode(head->label);
            src2new[head] = newhead;
            if(head->next&&!newhead->next)
                newhead->next = src2new.find(head->next)!=src2new.end()?src2new[head->next]:copyRandomList(head->next,src2new);
            if(head->random&&!newhead->random)
                newhead->random = src2new.find(head->random)!=src2new.end()?src2new[head->random]:copyRandomList(head->random,src2new); 
            return newhead;   
        }
    }
};
