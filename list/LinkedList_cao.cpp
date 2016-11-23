
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
/*---------1.单链表头插入(特殊情况)-------------*/
void insert(ListNode* head,ListNode* x){
    x->next = head;
    head = x;
}


/*---------2.单链表位置插入-----------*/
void insert(ListNode* head,ListNode* position,ListNode* x){
    if(position==head){//插入头节点,特殊情况
        x->next = head;
        head = x;
        return;
    }   
    for(pre=head;pre&&pre->next!=position;pre=pre->next);//寻找position的前驱
    if(!pre){
        cout<<"error position"<<endl;
    }else{
        x->next = pre->next; //就是position
        pre->next = x;
    }
    free(pre);
}
/*---------3.单链表删除节点-----------*/
void delete(ListNode* head,ListNode* x){
    if(head==x){
        ListNode* tmp = head->next;
        free(head);//释放删除的节点
        head = tmp;
        return ;
    }
    ListNode *pre;
    for(pre=head;pre&&pre->next!=x;pre=pre->next);
    if(pre){
        ListNode*tmp = pre->next;
        pre->next = tmp->next;
        free(tmp);
    }else{
        cout<<"has no x"<<endl;
    }
}
/*---------3.单链表懒删除-----------*/
void lazyDelete(ListNode* x){
    if(x->next){
        ListNode* tmp = x->tmp;
        x->val = tmp->val;
        x->next = tmp->next;
        free(tmp);
    }
}


/*单链表翻转*/
ListNode* reverseList(ListNode* head){
    ListNode* newhead=NULL;
    while(head){
        ListNode* tmp = head->next;//保存当前的下一个
        head->next = newhead;//newhead 保存了已经反转的前面部分链表的头指针
        newhead = head;
        head = tmp;
    }
    return newhead;
}
/*获取链表长度*/
int getLen(ListNode* head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}