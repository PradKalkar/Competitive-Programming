//This code is the implementation of the change problem using dp
//tabulation i.e bottom up approach
#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000

int main()
{
	int money; //the money for which you want change
	cin >> money;
	//now enter coin denominations
	int n; //number of denominations
	cin >> n;
	int coins[n];
	for (auto& i : coins)
	{
		cin >> i;
	}
	int dp[money + 1];
	dp[0] = 0;
	for (int i = 1; i <= money; i++)
	{
		dp[i] = INF;
		for (auto& den : coins)
		{
			dp[i] = min(dp[i], 1 + dp[i - den]);
		}
	}
	cout << dp[money] << '\n';
}