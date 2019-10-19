// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
	int x, n;
	cin >> x >> n;
	int* a = new int[n+1];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	a[n + 1] = x % n;
	for (int j = 0; j < n; j++)
	{
		cout<<a[a[n + 1]]<<" ";
		a[n + 1] = (a[n + 1] + 1) % n;
	}
}