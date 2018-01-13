# include<bits/stdc++.h>
using namespace std;

# define ElemType int
# define MAX_SIZE 5

typedef struct{
	ElemType cir_queue[MAX_SIZE];
	int front;
	int rear;
	int size;
} CirQueue;

void InitCirQueue(CirQueue &Q){
	Q.front = Q.rear = 0;
	Q.size = 0;
}

void push(CirQueue &Q, ElemType e){
	Q.cir_queue[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAX_SIZE;
	if(Q.size < MAX_SIZE)
		Q.size++;
}

int empty(CirQueue &Q){
	return Q.size == 0;
}

ElemType pop(CirQueue &Q){
	if(empty(Q))
		return 404;
	ElemType e = Q.cir_queue[Q.front];
	Q.front = (Q.front + 1) % MAX_SIZE;
	Q.size--;
	return e;
}

ElemType front(CirQueue &Q){
	if(empty(Q))
		return 404;
	return Q.cir_queue[Q.front];
}

int size(CirQueue &Q){
	return Q.size;
}

int main(){
	CirQueue Q;
	int i;
	InitCirQueue(Q);
	for(i=0; i<8; i++)
		push(Q, i);
	cout << size(Q) << " " << empty(Q) << " " << front(Q) << endl;
	for(i=0; i<4; i++)
		cout << pop(Q) << " ";
	cout << endl << size(Q) << " " << empty(Q) << " " << front(Q) << endl;
	for(i=0; i<4; i++)
		cout << pop(Q) << " ";
	cout << endl << size(Q) << " " << empty(Q) << " " << front(Q) << endl;
}

