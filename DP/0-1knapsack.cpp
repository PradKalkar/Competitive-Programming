//This is the program for the discrete knapsack problem wothout repetitions 
//This is also known as 0-1 knapsack(either take an item or dont take it)
//This is a bottom-up dp
//refer week6 lecture slides of coursera if you dont understand something

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;
    int weight[n + 1], value[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    int dp[n+1][W+1];
    fill_n(&dp[0][0], (n + 1) * (W + 1), 0);
// dp[i][w] -> this denotes the maximum value possible by using the 1st i items and with the knapsack of capacity w
    for (int i = 1; i <= n; i++)
    {
        //we take two possible cases
        //"take the weight[i]" and "don;t taking the weight[i]"
        //we are building the row number i i.e dp[i][1], dp[i][2], ....., dp[i][W] in every iteration
        for (int w = 1; w <= W; w++)
        {
            if (weight[i] <= w)
            {
                dp[i][w] = max(dp[i-1][w - weight[i]] + value[i], dp[i-1][w]);
                //take the maximum possible value of below two subproblems- 
                //1. ith item included in the knapsack
                //2. ith item not included in the knapsack
            }
            else
            {
                //here weight[i] cannot be included in the knapsack
                dp[i][w] = dp[i-1][w]; //weight[i] is not included in the knapsack
            }
        }
    }
    cout << "The maximum value possible to take in the knapsack is ";
    cout << dp[n][W] << '\n';
    //output the maximum possible value when all the n items are considered(some of them are taken and some are not
    //in the knapsack) to be put in the knapsack of weight W

    vector<bool> arr(n + 1); //by default false

    //now my job is to bactrace
    //fill the boolean array s.t. arr[i] = true if ith item is included in the knapsack
 
    int i = n, w = W;
    for (int j = n; j >= 1; j--){
        //take the jth item in the knapsack
        if (w >= weight[j] && dp[i][w] == dp[i-1][w - weight[j]] + value[j])
        {
            arr[j] = true;
            i--;
            w -= weight[j];
        }
        //dont take the jth item in the knapsack
        else if (dp[i][w] == dp[i-1][w])
        {
            arr[j] = false;
            i--;
        }
    }

    cout << "The items used in the knapsack for optimum ans are  ";
    for (int j = 1; j <= n; j++)
    {
        if (arr[j]) cout << j << ", ";
    }
}
