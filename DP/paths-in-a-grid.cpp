//finding the max sum path from the upper left corner to the right corner of given n x n matrix
//Time complexity - O(n^2)
//uses dp
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int arr[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	int sum[n][n] = {-1};
	sum[0][0] = arr[0][0];
	//computing 1st row
	for (int i = 1; i < n; i++)
	{
		sum[0][i] = sum[0][i - 1] + arr[0][i];
	}
	for (int i = 1; i < n; i++)
	{
		sum[i][0] = sum[i - 1][0] + arr[i][0];
		for (int j = 1; j < n; j++)
		{
			sum[i][j] = max(sum[i - 1][j] + arr[i][j], sum[i][j - 1] + arr[i][j]);
		}
	}
	cout << sum[n - 1][n - 1] << '\n';
}
