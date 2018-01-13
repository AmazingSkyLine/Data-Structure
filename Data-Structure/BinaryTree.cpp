# include<bits/stdc++.h>
using namespace std;

# define ElemType char

int node_num = 0;

typedef struct TNode{
	ElemType data;
	struct TNode *lchild;
	struct TNode *rchild;
}TNode, *PNode;

PNode CreateBinaryTree(PNode root){
	char input;
	cin >> input;
	if(input == '#'){
		root = NULL;
		return root;
	}
	root = new TNode;
	root->data = input; 
	node_num++;
	root->lchild = CreateBinaryTree(root->lchild);
	root->rchild = CreateBinaryTree(root->rchild);
	return root;
}

void front_Search(PNode root){
	if(!root)
		return;
	cout << root->data << " ";
	front_Search(root->lchild);
	front_Search(root->rchild);
}

void med_Search(PNode root){
	if(!root)
		return;
	med_Search(root->lchild);
	cout << root->data << " ";
	med_Search(root->rchild);
}

void back_Search(PNode root){
	if(!root)
		return;
	back_Search(root->lchild);
	back_Search(root->rchild);
	cout << root->data << " ";
}

int nodeNum(){
	return node_num;
}

int depth(PNode root){
	int ld, rd;
	if(!root)
		return 0;
	ld = 1 + depth(root->lchild);
	rd = 1 + depth(root->rchild);
	return ld > rd? ld: rd;
}

int main(){
	PNode root=NULL;
	root = CreateBinaryTree(root);
	front_Search(root);
	cout << endl;
	med_Search(root);
	cout << endl;
	back_Search(root);
	cout << endl;
	cout << nodeNum() << endl;
	cout << depth(root) << endl;
}
