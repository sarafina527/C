//str m  e.g. "abcdef" 3 =>"defabc"  链表
#include <stdio.h>

//------------rotate----------------------------
//#solution1 shift  T(n)=O(mn) S(n)=O(1)
void LeftShiftOne(char* str,int n){
	char head = str[0];
	for(int i=0;i<n-1;i++){
		str[i] = str[i+1];
	}
	str[n-1] = head;
}
char* rotateByShift (char* str,int n,int m) {
	//将str的前m个字符移到尾部，可以看作第一次把第一位移到最后，然后第二位，。。。然后第n位
	for(int j=0;j<m;j++){
		LeftShiftOne(str,n);
	}
	return str;
}

//#solution2 3reverse 两个子串反转（前m个，和后n-m个），合并后再翻转  T(n)=O(n) S(n)=O(1)
void reverse(char* sub1,int m){
	char *p=sub1,*q=sub1+m-1;
//	printf("%c %c\n",*p,*q);
	while(p<q){
		char temp = *p;
		*p = *q;
		*q = temp;
		p++;
		q--;
	}
}
char * rotateByReverse(char* str,int n,int m){
	reverse(str,m);
	reverse(str+m,n-m);
	reverse(str,n);
	return str;
}
//---------------------------------------

//-------------LinkedList reverse-------------
typedef struct node
{
	int val;
	node* next;
	node(int v):val(v),next(NULL){};

} node;

void addNode(node* head,int val){
	node* cur = new node(val);
	node* p = head;
	if(p==NULL){
		head = cur;
	}else{
		while(p->next!=NULL){
			p = p->next;
		}
		p->next = cur;
	}
	
	

}
void printLink(node* head){
	node *p = head;
	while(p!=NULL){
		printf("%d\t", p->val);
		p = p->next;
	}
}
node* reverseLinkedList(node* head){
	node *p=head,*q,*next;
	if(p!=NULL){
		q = p->next;
	}	
	while(q){
		next = q->next;
//		printf("%d %d\n",p->val,q->val);
		q->next = p;//reverse
		p = q;
		q = next;
	}
	head->next = NULL;
	head = p;
	return head;
}
node* reverseSplitByn(node* head,int n){
	node* sub1 = head,*sub2,*p=head;
	for(int i=1;i<n;i++){
		p=p->next;
	}
	sub2 = p->next;
	p->next = NULL;
	sub1 = reverseLinkedList(sub1);
	sub2 = reverseLinkedList(sub2);
	p = sub1;
	while(p->next){
		p = p->next;
	}
	p->next = sub2;
	return sub1;
}




int main(){
//	char s[]="abcdef";
//	char s2[]="abcdef";
//
//	printf("%s\n",rotateByShift(s,6,3));
//	
//	printf("%s\n",rotateByReverse(s2,6,3));

	//--------------------
	node* head = new node(1);
	for(int i=2;i<=6;i++){
		addNode(head,i);
	}
	head = reverseSplitByn(head,2);
	printLink(head);
}
