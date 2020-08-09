//Given a list of weights
//[w1,w2,...,wn], determine all sums that can be constructed using the weights.
//Time complexity - O(sum * n)
//This is better than knapsack1.cpp
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
	bool possible[sum + 1] = {false};
	possible[0] = true;
	for (int k = 1; k <= n; k++)
	{
		//if I would have done x = 0; x <= sum; x++
		//then the array index might have overflown
		for (int x = sum; x >= 0; x--)
		{
			if (possible[x]) possible[x + weights[k]] = true;
		}
	}
	vector<int> sums;
	for (int x = 0; x <= sum; x++)
	{
		if (possible[x]) sums.push_back(x);
	}
	for (auto& i : sums)
	{
		cout << i << ' ';
	}
}
