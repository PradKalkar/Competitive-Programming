#include <bits/stdc++.h>
using namespace std;

int calc(vector<int>& wt, vector<int>& val, int n, int W){
    if (n == 0 || W == 0) return 0;
    if (W < wt[n-1]){
        return calc(wt, val, n-1, W);
    }
    else{
        return max(calc(wt, val, n-1, W), val[n-1] + calc(wt, val, n-1, W - wt[n-1]));
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
    cout << calc(wt, val, n, W) << '\n';
}