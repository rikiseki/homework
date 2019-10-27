#include <iostream>
using namespace std;
#define MAXSIZE 1000
typedef struct Stack {
	int data[MAXSIZE];
	int top;
}* StackPtr;
typedef struct Queue {
	int data[MAXSIZE];
	int front, rear;
}* QueuePtr;

void Init_Stack(StackPtr S);
void Push_stack(StackPtr S, int e);
int Pop_Stack(StackPtr S);
void Init_Queue(QueuePtr Q);
void Enter_Queue(QueuePtr Q, int e);
int Delete_Queue(QueuePtr Q);
int main() {
	int n, x;
	cin >> n;
	StackPtr S=new Stack;
	QueuePtr Q=new Queue;
	Init_Stack(S);
	Init_Queue(Q);
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		Enter_Queue(Q, x);
	}
	for (int i = 0; i < n; i++)
	{
		int temp = Delete_Queue(Q);
		Push_stack(S, temp);
	}
	for (int i = 0; i < n; i++)
	{
		int temp = Pop_Stack(S);
		Enter_Queue(Q, temp);
	}
	for (int i = 0; i < n; i++)
	{
		x = Delete_Queue(Q);
		cout << x << " ";
	}
}

void Init_Stack(StackPtr S) {
	S->top = -1;
}
void Push_stack(StackPtr S, int e) {
	S->top++;
	S->data[S->top] = e;
}
int Pop_Stack(StackPtr S)
{
	return S->data[S->top--];
}
void Init_Queue(QueuePtr Q) {
	Q->front = Q->rear = -1;
}
void Enter_Queue(QueuePtr Q, int e)
{
	Q->rear = (Q->rear + 1) % MAXSIZE;
	Q->data[Q->rear] = e;
}
int Delete_Queue(QueuePtr Q) {
	Q->front = (Q->front + 1) % MAXSIZE;
	return Q->data[Q->front];
}
