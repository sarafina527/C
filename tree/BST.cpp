#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
using namespace std;
/**
 * 二叉树结点定义
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* BSTInsert(TreeNode* root,TreeNode* x);
/**
 * 创建二叉搜索树
 */
TreeNode* createBST(vector<int> &arr){
	TreeNode *root=NULL;
	for(int i=0;i<arr.size();i++){
		TreeNode* tmp = new TreeNode(arr[i]);
		root = BSTInsert(root,tmp);
	}
	return root;
}

/**
 * 中序遍历
 */
void inorderTreeWalk(TreeNode* root){
	if(root){
		inorderTreeWalk(root->left);
		cout<<root->val<<'\t';
		inorderTreeWalk(root->right);
	}
}
/**
 * BST排序，类似于快排
 */
void BSTSort(vector<int> &arr){
	TreeNode *root = createBST(arr);
	inorderTreeWalk(root);
}

/*--------------------检索-----------------------*/
/**
 * 递归搜索key
 */
TreeNode* BSTSearch(TreeNode* root,int x){
	TreeNode* ans = NULL;
	if(!root||root->val==x){
		return root;
	}
	if(x<root->val){
		return BSTSearch(root->left,x);
	}else{
		return BSTSearch(root->right,x);
	}
}

/**
 * 迭代搜索key
 */
TreeNode* BST_iterativeSearch(TreeNode* root,int x){
	while(root){
		if(root->val==x){
			break;
		}else if(x<root->val){
			root = root->left;
		}else{
			root = root->right;
		}
	}
	return root;
}
/**
 * 最小值
 */
TreeNode* BST_min(TreeNode* root){
	if(!root) return root;
	while(root->left){
		root = root->left;
	}
	return root;
}
/**
 * 最大值
 */
TreeNode* BST_max(TreeNode* root){
	if(!root) return root;
	while(root->right){
		root = root->right;
	}
	return root;
}
/**
 * 寻找父亲
 */
TreeNode* BST_parent(TreeNode* root,TreeNode* x){
	if(!root) return root;
	TreeNode* fa;
	while(root&&root!=x){
		fa = root;
		if(x->val<root->val){
			root = root->left;
		}else{
			root = root->right;
		}
	}
	if(root){
		return fa;
	}else{
		return NULL;
	}
}
/**
 * 搜索节点的中序后继节点
 * 有两种情况，一个若有右子树则是右子树的最小值（根据中序步骤）；否则还有一个是最近的以该节点所在为左子树的父亲，当前结点是左子树的最右
 */
TreeNode* BST_successor(TreeNode* root,TreeNode* x){
	if(!root) return NULL;
	if(x->right){
		return BST_min(x->right);
	}
	// TreeNode* fa = BST_parent(root,x);
	stack<TreeNode*> fa = stack<TreeNode*>();
	while(root&&root!=x){
		fa.push(root);//用栈存储x节点的向上路径
		if(x->val<root->val){
			root = root->left;
		}else{
			root = root->right;
		}
	}
	TreeNode* y = fa.top();

	while(!fa.empty()&&fa.top()->right == x){
		x = fa.top();
		fa.pop();
	}
	if(fa.empty()){
		return NULL;
	}else{
		return fa.top();
	}
}
/**
 * 搜索节点的中序前驱节点
 * 有两种情况，一个若有左子树则是左子树的最大值（根据中序步骤）；否则还有一个是最近的以该节点所在为右子树的父亲，当前结点是右子树的最左
 */
TreeNode* BST_predecessor(TreeNode* root,TreeNode* x){
	if(!root) return NULL;
	if(x->left){
		return BST_max(x->left);
	}
	// TreeNode* fa = BST_parent(root,x);
	stack<TreeNode*> fa = stack<TreeNode*>();
	while(root&&root!=x){
		fa.push(root);//用栈存储x节点的向上路径
		if(x->val<root->val){
			root = root->left;
		}else{
			root = root->right;
		}
	}
	TreeNode* y = fa.top();

	while(!fa.empty()&&fa.top()->left == x){
		x = fa.top();
		fa.pop();
	}
	if(fa.empty()){
		return NULL;
	}else{
		return fa.top();
	}
}
/*--------------------检索结束-------------------------*/

/*--------------------动态操作-------------------------*/
/**
 * 插入节点
 */
TreeNode* BSTInsert(TreeNode* root,TreeNode* x){
	TreeNode* fa=NULL,*cur = root;
	while(cur){//找到大小关系合适的叶子插入
		fa = cur;
		if(x->val<cur->val){
			cur = cur->left;
		}else{
			cur = cur->right;
		}
	}
	if(!fa){//树是空的，root=NULL
		root = x;
	}else{
		if(x->val<fa->val){//根据大小选择插入左边还是右边
			fa->left = x;
		}else{
			fa->right = x;
		}
	}
	return root;
}
/**
 * 删除节点
 * 分三种情况：
 * 1.没有左右子树，则直接空值代替
 * 2.只有一个子树，则直接越过当前结点，父节点连接其子树
 * 3.有两个子树，用其右子树的最小节点值替换当前结点值，并删除最小节点
 */
TreeNode* BSTDelete(TreeNode* root,TreeNode* x){
	TreeNode* wd;
	if(!x->left||!x->right){
		wd = x;
	}else{
		wd = BST_successor(root,x);
	}
	// cout<<wd->val<<endl;
	TreeNode* newchild;
	if(wd->left){
		newchild = wd->left;
	}else{
		newchild = wd->right;
	}
	cout<<"child "<<newchild<<endl;
	TreeNode* fa = BST_parent(root,wd);//应该找到待删除节点的父亲
	cout<<"fa "<<fa<<endl;
	
	if(!fa){//若待删除的是根
		root = newchild;
		cout<<newchild<<endl;
	}else{
		if(wd==fa->left){
			fa->left = newchild;
		}else{
			fa->right = newchild;
		}
	}
	if(wd!=x){
		x->val = wd->val;
		cout<<x->val<<endl;
	}
	free(wd);
	return root; 
	
}




int main(){
	//15,6,3,2,4,7,13,9,18,17,20
	vector<int> arr = vector<int>();
	arr.push_back(15);
	arr.push_back(6);
	arr.push_back(3);
	arr.push_back(2);
	arr.push_back(4);
	arr.push_back(7);
	arr.push_back(13);
	arr.push_back(9);
	arr.push_back(18);
	arr.push_back(17);
	arr.push_back(20);
	/*------create BST------------*/
	TreeNode* root = createBST(arr);
	/*------inorder BST------------*/
	cout<<"BST sort: ";
	inorderTreeWalk(root);
	cout<<endl;
	/*------BST search and successor------------*/
	TreeNode* n13 = BSTSearch(root,13);
	TreeNode* successorOfn13 = BST_successor(root,n13);
	cout<<"The successor of 13 is "<<successorOfn13->val<<endl;
	TreeNode* predecessorOf13 = BST_predecessor(root,n13);
	cout<<"The predecessor of 13 is "<<predecessorOf13->val<<endl;
	TreeNode* n15 = BSTSearch(root,15);
	TreeNode* successorOfn15 = BST_successor(root,n15);
	cout<<"The successor of 15 is "<<successorOfn15->val<<endl;
	TreeNode* predecessorOf15 = BST_predecessor(root,n15);
	cout<<"The predecessor of 15 is "<<predecessorOf15->val<<endl;
	/*------BST delete------------*/
	root = BSTDelete(root,n15);
	inorderTreeWalk(root);
	return 0;
}
