
/***************中序*****************/
void InorderTraversal( BinTree BT )
{
    if( BT ) {
        InorderTraversal( BT->Left );
        /* 此处假设对BT结点的访问就是打印数据 */
        printf("%d ", BT->Data); /* 假设数据为整型 */
        InorderTraversal( BT->Right );
    }
}
//非递归
void InOrderTraversal( BinTree BT )
{ 
    BinTree T=BT;
    Stack S = CreatStack( MaxSize ); /*创建并初始化堆栈S*/
    while( T || !IsEmpty(S) ){
        while(T){ /*一直向左并将沿途结点压入堆栈*/
            Push(S,T);
            T = T->Left;
        }
        if(!IsEmpty(S)){
            T = Pop(S); /*结点弹出堆栈*/
            printf(“%5d”, T->Data); /*（访问）打印结点*/
            T = T->Right; /*转向右子树*/
        }
    }
}
/**************************************/





/**************** 前序*****************/
void PreorderTraversal( BinTree BT )
{
    if( BT ) {
        printf("%d ", BT->Data );
        PreorderTraversal( BT->Left );
        PreorderTraversal( BT->Right );
    }
}


void PreOrderTraversal( BinTree BT )
{ 
    BinTree T=BT;
    Stack S = CreatStack( MaxSize ); /*创建并初始化堆栈S*/
    while( T || !IsEmpty(S) ){
        while(T){ /*一直向左并将沿途结点压入堆栈*/
            printf(“%5d”, T->Data); /*（访问）打印结点*/
            Push(S,T);
            T = T->Left;
        }
        if(!IsEmpty(S)){
            T = Pop(S); /*结点弹出堆栈*/           
            T = T->Right; /*转向右子树*/
        }
    }
}
/*********************************** */





/***************后序*****************/
void PostorderTraversal( BinTree BT )
{
    if( BT ) {
        PostorderTraversal( BT->Left );
        PostorderTraversal( BT->Right );
        printf("%d ", BT->Data);
    }
}
void PostOrderTraversal( BinTree BT )
{ 
    BinTree T=BT;
    Stack S = CreatStack( MaxSize ); /*创建并初始化堆栈S*/
    Stack Q = CreatStack( MaxSize ); /*创建并初始化队列Q,用于反向输出*/
    while( T || !IsEmpty(S) ){
        while(T){                    /*一直向右并将沿途结点压入堆栈*/
            Push(S,T);
            Push(Q,T);
            T = T->right;
        }
        if(!IsEmpty(S)){
            T = Pop(S); /*结点弹出堆栈*/ 
            T = T->left; /*转向左子树*/
        }
    }
    while(!IsEmpty(Q)){
        T = Pop(Q);
        printf("%d",T->Data);
    }
}
/**************************************/





/*****************层次*****************/
/***遍历从根结点开始，首先将根结点入队，然后开始执行循环：结点出队、访问该结点、其左右儿子入队*/
void LevelorderTraversal ( BinTree BT )
{ 
    Queue Q; 
    BinTree T; 
    if ( !BT ) return; /* 若是空树则直接返回 */
     
    Q = CreatQueue(); /* 创建空队列Q */
    AddQ( Q, BT );
    while ( !IsEmpty(Q) ) {
        T = DeleteQ( Q );
        printf("%d ", T->Data); /* 访问取出队列的结点 */
        if ( T->Left )   AddQ( Q, T->Left );
        if ( T->Right )  AddQ( Q, T->Right );
    }
}
/**************************************/

