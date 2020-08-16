#include <bits/stdc++.h>
using namespace std;
#define max3(a, b, c) max(max(a, b), c)

int main()
{
	int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    int m;
    cin >> m;
    vector<int> b(m);
    for (auto& i : b) cin >> i;
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 0; j <= m; j++) dp[0][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int insertion = dp[i][j-1];
            int deletion = dp[i-1][j];
            int mismatch = dp[i-1][j-1];
            int match = dp[i-1][j-1]+1;
            if (a[i-1] == b[j-1])
            {
                dp[i][j] = max3(insertion, deletion, match);
            }
            else
            {   
                dp[i][j] = max3(insertion, deletion, mismatch);
            }
        }
    }
    cout << dp[n][m] << '\n';
}
