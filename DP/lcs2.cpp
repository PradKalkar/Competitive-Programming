//Longest common subsequence of 3 sequences
//Think of it as the alignment game
//For insertion/deletion I loose x points, for correcting a mismatch  I loose y points and for a match I gain 1 point
//here x = y = 0
//maximum score in making 3 sequences equal to each other
#include <bits/stdc++.h>
using namespace std;
#define max3(a, b, c) max(a, max(b, c))
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
    int l;
    cin >> l;
    vector<int> c(l);
    for (auto& i : c) cin >> i;
    vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(m+1, vector<int>(l+1)));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= l; k++)
            {
                //dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1], dp[i-1][j-1][k], dp[i-1][j][k-1], dp[i][j-1][k-1], dp[i-1][j-1][k-1]
                dp[i][j][k] = max(max3(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]), max3(dp[i-1][j-1][k], dp[i-1][j][k-1], dp[i][j-1][k-1]));
                if (a[i-1] == b[j-1] && b[j-1] == c[k-1])
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1]+1);
                }
                else
                {
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k-1]);
                }
            }
        }
    }
    cout << dp[n][m][l] << '\n';
}
