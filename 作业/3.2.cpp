#include <iostream>
#include<stdio.h>
using namespace std;
 typedef struct Node
{
	int data;
	struct Node *next;
}*Pointer;
 int Find_Node(Pointer Head,int x)
 {
	 Pointer p=Head->next;
	 int j=0;
	 while((p->next)&&(j<x))
	 {
		 p=p->next;
		 j++;
	 }
	 if(j==x)
		return p->data;
	 else 
		return -1;
 }
 int  main()
 {
	 Pointer Head=new Node;
	 Head->next=NULL;
	 int k,cycle=1,x;
	 int len=0;
	 Pointer p=Head;
	 cin>>k;
	 while(cycle)
	 {
		cin>>x;
		if(x!=0)
		{
			Node *s = new Node;
			s->data = x;
			p->next = s;
			p = s;
			len++;
		}
		if(getchar()=='\n')
		{
			p->next = NULL;
			cycle = 0;
		}
	 }
	int n=Find_Node(Head,len-k);
	if(n>=0)
		cout<<n;
	else
		cout<<"Not Found";
	return 0;
 }
