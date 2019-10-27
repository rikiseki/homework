#include <iostream>
#define max 100
using namespace std;
typedef struct
{
	int i;
	int j;
	int v;
}node;
typedef struct
{
	int t;
	node data[max];
}TriTuple;
void create(TriTuple* a, TriTuple* b)
{
	cin >> a->t >> b->t;
	for (int i = 1; i <= a->t; i++)
	{
		cin >> a->data[i].i >> a->data[i].j >> a->data[i].v;
	}
	for (int i = 1; i <= b->t; i++)
	{
		cin >> b->data[i].i >> b->data[i].j >> b->data[i].v;
	}
}
int cmp(node m1, node m2)
{
	if (m1.i == m2.i)
	{
		if (m1.j == m2.j)
			return 0;
		else if (m1.j < m2.j)
			return -1;
		else
			return 1;
	}
	else if (m1.i < m2.i)
		return -1;
	else
		return 1;
}
void add(TriTuple* a, TriTuple* b, TriTuple* c)
{
	int p = 1, q = 1;
	int k = 1;
	while ((p <= a->t )&& (q <= b->t))
	{
		if (cmp(a->data[p], b->data[q]) == -1)
		{
			c->data[k].i = a->data[p].i;
			c->data[k].j = a->data[p].j;
			c->data[k].v = a->data[p].v;
			k++;
			p++;
		}
		else if (cmp(a->data[p], b->data[q]) == 1)
		{
			c->data[k].i = b->data[q].i;
			c->data[k].j = b->data[q].j;
			c->data[k].v = b->data[q].v;
			k++;
			q++;
		}
		else
		{
			c->data[k].i = b->data[q].i;
			c->data[k].j = b->data[q].j;
			c->data[k].v = b->data[q].v + a->data[p].v;
			k++;
			q++;
			p++;
		}

	}
	while (p <= a->t)
	{
		c->data[k].i = a->data[p].i;
		c->data[k].j = a->data[p].j;
		c->data[k].v = a->data[p].v;
		k++;
		p++;
	}
	while (q <= b->t)
	{
		c->data[k].i = b->data[q].i;
		c->data[k].j = b->data[q].j;
		c->data[k].v = b->data[q].v;
		k++;
		q++;
	}
	c->t = k-1;
}
void print(TriTuple* c)
{
	int count = 0;
	for (int i = 1; i <= c->t; i++)
	{
		if (c->data[i].v == 0)
		{
			count++;
		}
	}
	if (count != c->t)
	{
		for (int i = 1; i <= c->t; i++)
		{
			cout << c->data[i].i << " " << c->data[i].j << " " << c->data[i].v << endl;
		}
	}
	else {
		cout << -1 << " " << -1 << " " << -1;
	}
}
int main()
{
	TriTuple a, b, c;
	create(&a, &b);
	add(&a, &b, &c);
	print(&c);
}

