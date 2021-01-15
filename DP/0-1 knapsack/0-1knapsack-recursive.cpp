#include <bits/stdc++.h>
using namespace std;

int calc(vector<int>& wt, vector<int>& val, int n, int W){
    if (n == 0 || W == 0) return 0;
    int ans = calc(wt, val, n-1, W); //not selecting the last item
    if (W >= wt[n-1]) 
        ans = max(ans, val[n-1] + calc(wt, val, n-1, W - wt[n-1])); //selecting the last item
    return ans;
}

int main(){
    int n;
    cin >> n;
    int W;
    cin >> W;
    vector<int> wt(n), val(n);
    for (auto& i : wt) cin >> i;
    for (auto& i : val) cin >> i;
    cout << calc(wt, val, n, W) << '\n';
}