//This program outputs the minimum number of coins as well as the values of these coins
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
	//now we need to find the minimum nmber of coins required to exchange money
	//and also we need to output those coin values
	int value[money + 1]; //value[i] is the minimum number of coins to exchange i
	int first[money + 1]; //this stores the first coin for each change c
	value[0] = 0;
	for (int x = 1; x <= money; x++)
	{
		value[x] = INF;
		for (auto i : coins)
		{
			if (x - i >= 0 && value[x - i] + 1 < value[x])
			{
				value[x] = value[x - i] + 1;
				first[x] = i;
			}
		}
	}
	cout << "The minimum number of coins required are " << value[money] << '\n';
	//now outputting the values of coins
	cout << "The coins are : ";
	while (money > 0)
	{
		cout << first[money] << ' ';
		money -= first[money];
	}
}
