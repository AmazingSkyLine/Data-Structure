# include<bits/stdc++.h>
using namespace std;

# define ElemType int

typedef struct Node{
	ElemType data;
	struct Node *next;
}Node;

typedef struct{
	Node *tail;
	Node *front;
	int size;
}Queue;

void InitQueue(Queue &Q){
	Q.tail = new Node;
	Q.tail->next = NULL;
	Q.front = Q.tail;
	Q.size = 0;
}

void push(Queue &Q, ElemType e){
	Node *p = new Node;
	p->data = e;
	Q.tail->next = p;
	Q.tail = p;
	Q.size++;
}

int empty(Queue &Q){
	return Q.size == 0;
}

ElemType pop(Queue &Q){
	if(empty(Q))
		return 404;
	Node *q = Q.front->next;
	ElemType e = q->data;
	Q.front->next = q->next;
	delete q;
	Q.size--;
	return e;
}

int size(Queue &Q){
	return Q.size;
}

int front(Queue &Q){
	if(empty(Q))
		return 404;
	return Q.front->next->data;
}

int main(){
	Queue Q;
	InitQueue(Q);
	push(Q, 1);
	push(Q, 2);
	push(Q, 3);
	push(Q, 4);
	cout << size(Q) << " " << empty(Q) << endl;
	pop(Q);
	cout << size(Q) << " " << front(Q) << endl;
	pop(Q);
	pop(Q);
	cout << pop(Q) << " ";
	cout << size(Q);
	return 0;
}
