//Given a list of weights
//[w1,w2,...,wn], determine all sums that can be constructed using the weights.
//Time complexity - O(sum * n)
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int weights[n + 1];
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> weights[i];
		sum += weights[i];
	}
	bool possible[sum + 1][n + 1] = {false};
	//possible[x][k] states whether it is possible to make sum x from 1st k elements
	possible[0][0] = true;
	for (int k = 1; k <= n; k++)
	{
		for (int x = 0; x <= sum; x++)
		{
			possible[x][k] |= possible[x][k - 1];
			if (x - weights[k] >= 0) possible[x][k] |= possible[x - weights[k]][k - 1];
		}
	}
	vector<int> sums;
	for (int x = 0; x <= sum; x++)
	{
		if (possible[x][n]) sums.push_back(x);
	}
	for (auto& i : sums)
	{
		cout << i << ' ';
	}
}
