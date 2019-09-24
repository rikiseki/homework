#include <iostream>
#include<stdio.h>
using namespace std;
 typedef struct Node
{
	int data;
	struct Node *link;
}*Pointer;
void moveMax(Pointer list)
{
	Pointer p = list->link;
	Pointer pre =list;
	Pointer max = p;
	Pointer maxp = pre;
	while (p != NULL)
	{
		if (p->data > max->data)
		{
			max = p;
			maxp = pre;
		}
		pre = p;
		p = p->link;
	}
	while (max ->link!= NULL)
	{
		maxp->link = max->link;
		pre->link = max;
		max->link = NULL;
	}
}
void print(Pointer List)
{
	Pointer p = List->link;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->link;
	}
}
int main()
{
	Pointer List = new Node;
	List->link = NULL;
	int x,cycle=1;
	Pointer p = List;
	while (cycle)
	{
		cin >> x;
		if (x!=0)
		{
			Node *s = new Node;
			s->data = x;
			p->link = s;
			p = s;
		}
		if(getchar()== '\n')
		{
			p->link = NULL;
			cycle = 0;
		}
	}
	moveMax(List);
	print(List);
	return 0;
}




