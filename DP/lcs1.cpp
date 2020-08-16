#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a, b;
vector<vector<int> > dp;

void build_lcs(vector<int>& d, int i, int j)
{
    //use backtracking
    if (i == 0 && j == 0) return;
    bool done = false;
    if (i > 0 && j > 0)
    {
        if (a[i-1] == b[j-1])
        {
            if (dp[i][j] == dp[i-1][j-1]+1)
            {
                build_lcs(d, i-1, j-1);
                d.push_back(a[i-1]);
                done = true;
            }
        }
        else
        {
            if (dp[i][j] == dp[i-1][j-1])
            {
                build_lcs(d, i-1, j-1);
                done = true;
            }
        }
    }
    if (i > 0 && dp[i][j] == dp[i-1][j] && !done)
    {
        build_lcs(d, i-1, j);
        done = true;
    }
    if (j > 0 && dp[i][j] == dp[i][j-1] && !done)
    {
        build_lcs(d, i, j-1);
        done = true;
    }
}

int main()
{
    cin >> n;
    a.resize(n);
    for (auto& i : a) cin >> i;
    cin >> m;
    b.resize(m);
    for (auto& i : b) cin >> i;
    dp = vector<vector<int> >(n+1, vector<int>(m+1));
    vector<int> d; //lcs of a and b
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
                dp[i][j] = max(max(insertion, deletion), match);
            }
            else
            {
                dp[i][j] = max(max(insertion, deletion), mismatch);
            }   
        }
    }
    build_lcs(d, n, m);
    //The LCS of a and b is:
    for (auto& i : d) cout << i << ' ';
}
