//another dp solution to coin change problem using top - down approach i.e. memoization
#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000

void recurse(int money, vector<int>& dp, vector<int>& coins)
{
	for (auto& den : coins)
	{
		if (money < den)
			continue;
		if (dp[money - den] == -1)
			recurse(money - den, dp, coins);
		if (dp[money - den] == -1) dp[money - den] = INF;
		if (dp[money] == -1)
			dp[money] = min(dp[money - den] + 1, INF);
		else
			dp[money] = min(dp[money], dp[money - den] + 1);
	}
}

int main()
{
	int money;
	cin >> money;
	int n;
	cin >> n;
	vector<int> coins(n);
	for (auto& i : coins) cin >> i;
	vector<int> dp(money + 1, -1);
	//-1 means not yet computed and INF means not possible
	dp[0] = 0;
	recurse(money, dp, coins);
	cout << dp[money] << '\n';
}