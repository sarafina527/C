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
        if(!l1&&!l2) return NULL;
        ListNode*big=l1,*small=l2,*bigsub,*ans,*anstail,*tmp;
        int len1=0,len2=0,diff,nextc;
        while(big){
        	len1++;
        	big = big->next;
        }
        while(small){
        	len2++;
        	small = small->next;
        }
        if(len1>=len2){
        	diff = len1 - len2;
        	big = l1;
        	small = l2;
        }else{
        	diff = len2 - len1;
        	big = l2;
        	small = l1;
        }
        if(diff==0)//等长的链直接相加
            ans = addTwoEqLenNumbers(big,small,nextc);
        else{//将长链后面与短链等长相加
            bigsub = big;
            ans = anstail = new ListNode(big->val);
            for(int i=1;i<diff;i++){
            	bigsub = bigsub->next;
            	anstail->next = new ListNode(bigsub->val);
            	anstail = anstail->next;
            }
            tmp = addTwoEqLenNumbers(bigsub->next,small,nextc);
            if(nextc)
        	    nextc = addOne(ans);
        	anstail->next = tmp;
        }
        if(nextc){//最后进位
        	ListNode *p = new ListNode(nextc);
        	p->next = ans;
        	ans = p;
        }
        return ans;
    }
    ListNode* addTwoEqLenNumbers(ListNode* l1,ListNode* l2,int &c){//两个等长的链相加，c是进位
    	if(!l1&&!l2){
    		c=0;
    		return NULL;
    	}
    	int nextc = 0;
    	ListNode* cur = new ListNode(0);
    	cur->next = addTwoEqLenNumbers(l1->next,l2->next,nextc);
    	int tmp = l1->val+l2->val+nextc;
    	c = tmp/10;
    	cur->val = tmp%10;
    	return cur;
    }
    int addOne(ListNode* l1){//将一条链从末尾加1
    	if(!l1) return 0;
    	else if(!l1->next){
    		int tmp = l1->val+1;
    		l1->val = tmp%10;
    		return tmp/10;
    	}else{
    		int c = addOne(l1->next);
    		if(c){
    			int tmp = l1->val+c;
    			l1->val = tmp%10;
    			return tmp/10;
    		}else
    			return 0;
    	}
    }
};