# include<bits/stdc++.h>
using namespace std;

# define ElemType int

typedef struct Node{
	ElemType data;
	struct Node *next;
	struct Node *pre;
}Node;

typedef struct{
	Node *tail;
	Node *front;
	int size;
}DeQueue;

void InitDeQueue(DeQueue &Q){
	Q.tail = new Node;
	Q.tail->pre = Q.tail->next = NULL;
	Q.front = Q.tail;
	Q.size = 0;
}

void push_back(DeQueue &Q, ElemType e){
	Node *p = new Node;
	p->data = e;
	p->next = Q.tail->next;
	Q.tail->next = p;
	p->pre = Q.tail;
	Q.tail = p;
	Q.size++;
}

void push_front(DeQueue &Q, ElemType e){
	Node *p = new Node;
	p->data = e;
	if(Q.front->next)
		Q.front->next->pre = p;
	p->next = Q.front->next;
	Q.front->next = p;
	p->pre = Q.front;
	for(p; p->next; p=p->next);
	Q.tail = p; 
	Q.size++;
}

int empty(DeQueue &Q){
	return Q.size == 0;
}

ElemType pop_front(DeQueue &Q){
	if(empty(Q))
		return 404;
	Node *q = Q.front->next;
	ElemType e = q->data;
	Q.front->next = q->next;
	q->next->pre = Q.front;
	delete q;
	Q.size--;
	return e;
}

ElemType pop_back(DeQueue &Q){
	if(empty(Q))
		return 404;
	Node *q = Q.tail;
	ElemType e = q->data;
	q->pre->next = NULL;
	Q.tail = q->pre;
	delete q;
	Q.size--;
	return e;
}

int size(DeQueue &Q){
	return Q.size;
}

int top(DeQueue &Q){
	if(empty(Q))
		return 404;
	return Q.front->next->data;
}

int tail(DeQueue &Q){
	if(empty(Q))
		return 404;
	return Q.tail->data;
}

int main(){
	DeQueue Q;
	InitDeQueue(Q);
	push_front(Q, 1);
	push_back(Q, 2);
	push_front(Q, 3);
	push_back(Q, 4);
	cout << size(Q) << " " << empty(Q) << endl;
	cout << top(Q) << " " << tail(Q) << " ";
	pop_front(Q);
	cout << size(Q) << " " << endl;
	pop_back(Q);
	pop_front(Q);
	cout << pop_back(Q) << " ";
	cout << size(Q) << endl;
	cout << pop_back(Q);
	return 0;
}
