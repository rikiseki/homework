#include <iostream>
using namespace std;
typedef struct node 
{
	int num;
	struct node* next;
}*Pointer;
int main()
{
	int m, n;
	cin >> m >> n;
	Pointer head = new node;
	head->num = 1;
	head->next = head;
	Pointer p = head;
	for (int i = 2; i <= n; i++)
	{
		node* s = new node;
		s->num = i;
		p->next = s;
		s->next = head;
		p = s;
	}
	Pointer q = head;
	Pointer r;
	while (q->next != p)
	{
		for (int i = 1; i < m; i++)
		{
			r = q;
			q = q->next;
		}
		r->next = q->next;
		cout << q->num;
		free(q);
		q = r->next;
	}

	cout << q->num;
	return 0;
}



