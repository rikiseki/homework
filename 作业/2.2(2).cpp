#include <iostream>
using namespace std;
#include<stack>
#include<queue>
int main()
{
	stack<int> s;
	queue<int> q;
	int n,x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		q.push(x);
	}
	for (int i = 0; i < n; i++)
	{
		int temp;
		temp = q.front();
		s.push(temp);
		q.pop();
	}
	for (int i = 0; i < n; i++)
	{
		int temp;
		temp = s.top();
		q.push(temp);
		s.pop();
	}
	for (int i = 0; i < n; i++)
	{
		cout << q.front() << " ";
		q.pop();
	}

}

