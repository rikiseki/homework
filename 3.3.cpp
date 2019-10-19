#include<iostream>
using namespace std;
typedef struct Node
{
	int num;
	int score;
	struct Node *next;
}*Pointer;
void print(Pointer head)
{
	Pointer p = head->next;
	while (p != NULL)
	{
		cout << "[num="<<p->num<<",score="<<p->score<<"]"<<endl;
		p = p->next;
	}
}
int main()
{
	Pointer head=new Node;
	head->next=NULL;
	Pointer p=head;
	int x,y;
	for(int i=0;i<3;i++)
	{
		Node *k=new Node;
		cin>>x>>y;
		k->num=x;
		k->score=y;
		p->next=k;
		k->next=NULL;
		p=k;
	}
	print(head);
	return 0;
}
