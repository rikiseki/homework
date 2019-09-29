#include <iostream>
#include<stdio.h>
 using namespace std;
int Find_N(int *a,int n)
{
	int ntime = 0;
	int k = 0;
	int result=-1;
	for (int i = 0; i < n; i++)
	{
		if (ntime == 0)
		{
			result = a[i];
			ntime = 1;
		}
		else
		{
			if (result == a[i])
			{
				ntime++;
			}
			else
			{
				ntime--;
			}
		}
	}
    for(int j=0;j<n;j++)
	{
		if (result == a[j])
			k++;
	}
	if (k <= n / 2)
		return -1;
	else
		return result;
}
int main()
{
	int a[100];
	int cycle = 1;
	int n = 0;
	while (cycle)
	{
		cin >> a[n];
		n++;
		if(getchar()=='\n')
		{
			cycle = 0;
		}
	}
	cout << Find_N(a, n);
}


