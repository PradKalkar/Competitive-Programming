//The edit distance or Levenshtein distance1 is the minimum number of editing operations needed to transform a 
//string into another string.
/*The allowed
editing operations are as follows:
• insert a character (e.g. ABC -> ABCA)
• remove a character (e.g. ABC -> AC)
• modify a character (e.g. ABC -> ADC)
*/
//https://www.youtube.com/watch?v=We3YDTzNXEk
//also see CP handbook pg 74, 75
#include <bits/stdc++.h>
using namespace std;
#define min3(a, b, c) min(min(a, b), c)
#define sz(a) (int(a.size()))

int main()
{
	string a, b;
	cin >> a >> b;
	//we have to convert a to b
	int dp[sz(b) + 1][sz(a) + 1];
	for (int i = 0; i <= sz(b); i++) dp[i][0] = i;
	for (int j = 0; j <= sz(a); j++) dp[0][j] = j;
	for (int i = 1; i <= sz(b); i++)
	{
		for (int j = 1; j <= sz(a); j++)
		{
			//dp[i][j]
			if (a[j-1] == b[i-1])
			{
				dp[i][j] = min3(dp[i-1][j]+1, dp[i-1][j-1], dp[i][j-1] + 1);
			}
			else
			{
				dp[i][j] = min3(dp[i-1][j]+1, dp[i-1][j-1] + 1, dp[i][j-1] + 1);				
			}
		}
	}
	cout << dp[sz(b)][sz(a)] << '\n';
	//now constructing the sequence
	vector<string> ops;
	int i = sz(b), j = sz(a);
	while (1)
	{
		if (i == 0 && j == 0) break;
		if (a[j-1] == b[i-1])
		{
			if (dp[i][j] == dp[i-1][j-1])
			{
				//do nothing
				i--, j--;
				continue;
			}	
		}
		else
		{
			if (dp[i][j] == dp[i-1][j-1] + 1)
			{
				ops.push_back("change " + string(1, a[j-1]) + " to " + string(1, b[i-1]));				
				i--, j--;
				continue;
			}	
		}
		if (dp[i][j] == dp[i-1][j] + 1)
		{
			ops.push_back("insert " + string(1, b[i-1]));
			i--;
		}
		else //if dp[i][j] == dp[i][j-1]+1
		{
			ops.push_back("delete " + string(1, a[j-1]));			
			j--;
		}
	}
	reverse(begin(ops), end(ops));
	cout << "Do the following operations for converting " << a << " to " << b << ":\n";
	for (auto& i : ops) cout << i << '\n';	
}
