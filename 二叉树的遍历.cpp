#include <iostream>
#include<vector>
#include<stack>
using namespace std;
typedef struct btnode
{
	int data;
	struct btnode* lchild;
	struct btnode* rchild;
}*bitreptr;
void create(bitreptr& t)
{
	int x;
	cin >> x;
	if (x == 0)
		t = NULL;
	else
	{
		bitreptr p = new btnode;
		p->data = x;
		t = p;
		create(t->lchild);
		create(t->rchild);
	}
}
void Preorder(bitreptr t)
{
	stack<bitreptr> s;
	bitreptr p = new btnode;
	p = t;
	if (!p)
		return;
	while (p||!s.empty())
	{
		while (p)
		{
			cout << p->data<<" ";
			s.push(p);
			p = p->lchild;
		}
		p = s.top();
		s.pop();
		p = p->rchild;
	}
	cout << endl;
}
void Inorder(bitreptr t)
{
	stack<bitreptr> s;
	bitreptr p = new btnode;
	p = t;
	if (!p)
		return;
	while (p || !s.empty())
	{
		while (p)
		{
			s.push(p);
			p = p->lchild;
		}
		p = s.top();
		s.pop();
		cout << p->data<<" ";
		p = p->rchild;
	}
	cout << endl;
}
void Postorder(bitreptr t)
{
	stack<bitreptr> s;
	bitreptr p = new btnode;
	bitreptr pre = new btnode;
	p = t;
	pre = NULL;
	if (!p)
		return;
	while (p || !s.empty())
	{
		while (p)
		{
			s.push(p);
			p = p->lchild;
		}
		p = s.top();
		if (!p->rchild || pre == p->rchild) {
			s.pop();
			cout << p->data << " ";
			pre = p;
			p = NULL;
		}
		else {
			p = p->rchild;
			pre = NULL;
		}
	}
	cout << endl;
}
int main()
{
	bitreptr root = new btnode;
	create(root);
	Preorder(root);
	Inorder(root);
	Postorder(root);
}

