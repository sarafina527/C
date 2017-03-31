#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <stack>

using namespace std;

typedef struct BinTree{
	int v;     //value
	BinTree* left; // leftChild;
	BinTree* right; //rightChild;
	BinTree(int val){
		v = val;
		left = NULL;
		right = NULL;
	} 
} BT, *PBT;

//Create binary tree
PBT CreateBinTree(char *str);

 char strBinTree[] = 
"+1\n"
" -2\n"
"  -4\n"
"  -5\n"
"   -6\n"
"   -7\n"
" -3\n"
"  -13\n"
"  -8\n"
"   -9\n"
"   -10\n"
"    -11\n"
"    -12\n";
/*
    1
   / \
  /   \
 2     3
 / \   / \
4  5  13  8
  / \    /  \
  6  7  9   10
            / \
     	   11  12
*/		
PBT CreateBinTree( char *str)
{
	//preorder & space
	PBT root = NULL;
	stack<PBT> parent;
	stack<int> spacenum;
	char* p = str,*q = str;
	while(p!=NULL&&*p!=0){
		if(*p=='+'){
			int tmp = 0;
			for(p = p+1;*p!='\n';p++){
				tmp = tmp*10+*p-'0';
			}
			root = new BT(tmp);
			parent.push(root);
			spacenum.push(0);
			p++;
		}
		if(*p==' '){
			int tmp = 0;
			int sn = 0;
			for(;*p!='-';p++){
				if(*p==' ')
					sn++;
			}
			for(p=p+1;*p!='\n';p++){
				tmp = tmp*10+*p-'0';
			}
			PBT cur = new BT(tmp);
			while(sn!=spacenum.top()+1){//找到当前结点的
				spacenum.pop();
				parent.pop();
			}
			PBT pi = parent.top();
			if(pi->left==NULL){
				pi->left = cur;
			}else if(pi->right==NULL)
				pi->right = cur;
			parent.push(cur);
			spacenum.push(sn);
			p++;
		}
	}
	return root;
}
bool IsBranch(BinTree* root, int nodeList[],int nodeListSize){
	if(!root&&!nodeListSize)
		return true;
	else if(!root)
		return false;
	else if(!nodeListSize)
		return false;
	else{
		int rootval = root->v;
		for(int i=0;i<nodeListSize;i++){
			if(nodeList[i]==rootval){
				int tmp = nodeList[i];
				nodeList[i] = nodeList[nodeListSize-1];
				nodeList[nodeListSize-1] = tmp;
				if(IsBranch(root->left,nodeList,nodeListSize-1))
					return true;
				if(IsBranch(root->right,nodeList,nodeListSize-1))
					return true;
				break;
			}
		}
		return false;
	}
	
}


void printTree(PBT root){
	if(root){
		printf("%d\t",root->v);
		printTree(root->left);
		printTree(root->right);
	}	
}
int main(int argc, char* argv[])
{
	PBT root = NULL;
	int nodeListSize = 0;

	//input node list size
	cin >> nodeListSize;
	int* NodeList = new int[nodeListSize];
	if (NodeList == NULL)
		return 0;

	//input each node
	for (int i = 0; i < nodeListSize; i++)
		cin >> NodeList[i];
	root= CreateBinTree(strBinTree);
	bool bIsBranch = IsBranch(root, NodeList, nodeListSize);
	if (bIsBranch)
		printf("true");
	else
		printf("false");

	if (NodeList)
		delete[]NodeList, NodeList=NULL;
	//printTree(root);
	return 0;
}
