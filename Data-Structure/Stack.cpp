# include<bits/stdc++.h>
using namespace std;

# define ElemType int

typedef struct Node{
	struct Node *next;
	ElemType data;
}Node;

typedef struct{
	Node *head;
	Node *top;
	int size;
}Stack;

void InitStack(Stack &S){
	S.head = new Node;
	S.head->next = NULL;
	S.top = S.head;
	S.size = 0;
}

void push(Stack &S, ElemType e){
	Node *p = new Node;
	p->data = e;
	S.top->next = p;
	S.top = p;
	S.size++;
}

int empty(Stack &S){
	return S.size==0;
}

ElemType pop(Stack &S){
	if(empty(S))
		return 404;
	Node *p = S.head;
	while(p->next != S.top)
		p = p->next;
	S.top = p;
	Node *q = p->next;
	ElemType e = q->data;
	delete q;
	p->next = NULL;
	S.size--;
	return e;
}

ElemType top(Stack &S){
	if(empty(Q))
		return 404;
	return S.top->data;
}

int size(Stack &S){
	return S.size;
}

int main(){
	Stack S;
	InitStack(S);
	push(S, 1);
	push(S, 2);
	push(S, 3);
	push(S, 4);
	cout << size(S) << " " << empty(S) << endl;
	pop(S);
	cout << size(S) << " " << top(S) << endl;
	pop(S);
	pop(S);
	cout << pop(S) << " ";
	cout << size(S);
	return 0;
}

