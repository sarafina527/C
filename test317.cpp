#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
ListNode* construct(vector<int> &nums,int p){
    if(p==nums.size())
        return NULL;
    ListNode* head= new ListNode(nums[p]);
    head->next = construct(nums,p+1);
    return head;
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
    
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int alen=0,blen=0,offset;
        ListNode* it = headA,*llist,*shlist,*ans;
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

    
    int main(){
    	vector<int> numsa(2,1);
        vector<int> numsb(3,2);
        vector<int> numsc(3,3);
        ListNode* headA = construct(numsa,0);
        ListNode* headB = construct(numsb,0);
        ListNode* headC = construct(numsc,0);
        
        ListNode* target = getIntersectionNode(headB,headC);
        cout<<target<<" "<<headC<<" "<<endl;
        ListNode* p = headA;
        while(p&&p->next){
            p = p->next;
        }
        p->next = headC;
        p = headB;
        while(p&&p->next){
            p = p->next;
        }
        p->next = headC;
        target = getIntersectionNode(headA,headB);
        cout<<target<<" "<<headC<<" "<<endl;
        
        numsa[0] = 1;
        numsa[1] = 3;
        
        numsb[0] = 2;
        numsb[1] = 4;
        numsb[2] = 6;
        for(int i=4;i<=11;i++){
        	numsb.push_back(i*2);
		}
		headA = construct(numsa,0);
		headB = construct(numsb,0);
		target = getIntersectionNode(headA,headB);
        cout<<target<<" "<<headC<<" "<<endl;

	} 


