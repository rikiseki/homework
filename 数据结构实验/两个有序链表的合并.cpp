#include <iostream>
#include<vector>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}*Pointer;
Pointer create()
{
	Pointer list = new node;
	list->next = NULL;
	Pointer p = list;
	int x; 
	while (cin >> x)
	{
		Pointer s = new node;
		s->data = x;
		p->next = s;
		s->next = NULL;
		p = s;
		if (cin.get() == '\n')
			break;
	}
	return list;
}
Pointer mergeTwoLists(Pointer l1, Pointer l2) {
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;
	else if (l1->data < l2->data)
	{
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists(l2->next, l1);
		return l2;
	}
}
void print(Pointer h)
{
	Pointer p=h;
	while(p!=NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
int main()
{
	Pointer h1 = create();
	Pointer h2 = create();
	h1=mergeTwoLists(h1->next, h2->next);
	print(h1);
}





