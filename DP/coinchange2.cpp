#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;

int main()
{
	int money;
	cin >> money;
	int n; //number of denominations
	cin >> n;
	int coins[n];
	for (auto& i : coins) cin >> i; //the values of denominations
	int cnt[money + 1] = {0};
	cnt[0] = 1; //there is 1 way to choose for making 0 and it is "Dont choose any coin"
	for (int x = 1; x <= money; x++)
	{
		for (auto c : coins)
		{
			if (x - c >= 0)
			{
				cnt[x] += cnt[x - c];
			}
		}
	}
	cout << "The number of ways to give change for money are " << cnt[money] << '\n';
}
