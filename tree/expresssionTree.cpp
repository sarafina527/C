#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct BinaryNode
{
	char data;
	BinaryNode *left;
	BinaryNode *right;
	BinaryNode(char c):data(c),left(NULL),right(NULL){};
};
void preOrder(BinaryNode *root);
BinaryNode * createByPost(string str);
void MidOrder(BinaryNode *root);

int main(){
	string poststr = "ab+cde+**";
	BinaryNode *root = createByPost(poststr);
	cout<<endl;
	preOrder(root);
	cout<<endl;
	MidOrder(root);

	
}
void preOrder(BinaryNode *root){
	if(root!=NULL){
		cout<<root->data;
		//遍历所需操作
		preOrder(root->left);
		preOrder(root->right);
	}
	
}
void MidOrder(BinaryNode *root){	
	if(root!=NULL){
		MidOrder(root->left);
		cout<<root->data;
		MidOrder(root->right);
	}		
}
BinaryNode * createByPost(string str){
	stack<BinaryNode *> stk;
	BinaryNode *root;
	for(int i=0;i<str.size();i++){
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
			BinaryNode *opt = new BinaryNode(str[i]);
			cout<<opt->data;
			BinaryNode *right = stk.top();
			stk.pop();
			BinaryNode *left = stk.top();
			stk.pop();
			opt->left = left;
			opt->right = right;
			stk.push(opt);
		}else{
			BinaryNode *temp = new BinaryNode(str[i]);
			cout<<temp->data;
			stk.push(temp);
		}
	}
	
	root = stk.top();
	return root;
	

}
