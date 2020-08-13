//The edit distance or Levenshtein distance1 is the minimum number of editing operations needed to transform a 
//string into another string.
/*The allowed
editing operations are as follows:
• insert a character (e.g. ABC -> ABCA)
• remove a character (e.g. ABC -> AC)
• modify a character (e.g. ABC -> ADC)
*/
//see the moscow notebook, cp handbook(pg 74) and coursera lecture week 5 (algorithmic toolbox)
//using edit distance to find the longest common subsequence of given strings
#include <bits/stdc++.h>
using namespace std;
#define min3(a, b, c) min(min(a, b), c)
#define sz(a) (int(a.size()))
string a, b;
string longest_common_subsequence;

void output_process(int i, int j, const vector<vector<int> >& dp)
{
	if (i == 0 && j == 0) return;
	if (i > 0 && dp[i][j] == dp[i-1][j]+1)
	{
		output_process(i-1, j, dp); 
		cout << "delete " << a[i] << '\n';
	}
	else if (j > 0 && dp[i][j] == dp[i][j-1]+1)
	{
		output_process(i, j-1, dp);
		cout << "insert " << b[j] << '\n';
	}
	else
	{
		output_process(i-1, j-1, dp);
		if (a[i] == b[j]) 
		{
			cout << "leave " << a[i] << " as it is\n";
			longest_common_subsequence.push_back(a[i]);
		}
		else cout << "change " << a[i] << " to " << b[j] << '\n';	
	}
}

int main()
{
	string tmpa, tmpb;
	cin >> tmpa >> tmpb;
	int n = sz(tmpa), m = sz(tmpb);
	vector<vector<int> > dp(n+1, vector<int>(m+1));
	a = string(sz(tmpa) + 1, '\0'), b = string(sz(tmpb) + 1, '\0'); //making a and b as 1 indexed strings
	for (int i = 1; i <= n; i++) a[i] = tmpa[i-1];
	for (int j = 1; j <= m; j++) b[j] = tmpb[j-1];
	//we have to convert a to b
	for (int i = 0; i < n + 1; i++)
	{
		dp[i][0] = i;
	}
	for (int j = 0; j < m + 1; j++)
	{
		dp[0][j] = j;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int insertion = dp[i][j-1]+1;
			int deletion = dp[i-1][j]+1;
			int match = dp[i-1][j-1];
			int mismatch = dp[i-1][j-1]+1;
			if (a[i] == b[j])
				dp[i][j] = min3(insertion, deletion, match);
			else
				dp[i][j] = min3(insertion, deletion, mismatch);
		}
	}
	cout << dp[n][m] << '\n';
	cout << "To obtain" << b << " from" << a << " do the following\n";
	output_process(n, m, dp);
	cout << "The longest common subsequence in a and b is " << longest_common_subsequence << '\n';
}
