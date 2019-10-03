#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int k = 1;
	int a[10][10] = {0};
	int x = 0, y = 0;
	a[x][y] = 1;
	while (n * n!=k)
	{
		while (y + 1 < n && !a[x][y + 1])
			a[x][++y] = ++k;
		while (x + 1 < n && !a[x+1][y])
			a[++x][y] = ++k;
		while (y -1 >= 0 && !a[x][y - 1])
			a[x][--y] = ++k;
		while (x-1>=0 && !a[x-1][y])
			a[--x][y] = ++k;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
