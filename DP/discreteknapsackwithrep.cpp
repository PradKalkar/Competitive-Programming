//This is a program for the discrete kanpsack with repetitions allowed
//i.e we can take any item any number of times

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    //n is the number of items
    //W is the weight of the knapsack
    cin >> n >> W;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0); //order = [0, 1, 2, ..., n-1]
    vector<int> dp(W + 1);
    for (int i = 0; i <= W; i++)
    {
        for (auto& j : order)
        {
            if (weight[j] <= i){
                dp[i] = max(dp[i], dp[i - weight[j]] + value[j]);
            }
        }
    }
    cout << dp[W];
}
