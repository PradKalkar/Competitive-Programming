#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int calc(vector<int>& wt, vector<int>& val, int n, int W){
    if (n == 0 || W == 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];

    if (W < wt[n-1]){
        return dp[n][W] = calc(wt, val, n-1, W);
    }
    else{
        return dp[n][W] = max(calc(wt, val, n-1, W), val[n-1] + calc(wt, val, n-1, W - wt[n-1]));
    }
}

int main(){
    int n;
    cin >> n;
    int W;
    cin >> W;
    vector<int> wt(n), val(n);
    for (auto& i : wt) cin >> i;
    for (auto& i : val) cin >> i;
    dp = vector<vector<int>> (n+1, vector<int>(W+1, -1)); //the value is -1 if the value is not yet stored
    cout << calc(wt, val, n, W) << '\n';
}