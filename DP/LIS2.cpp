/*Our first problem is to find the longest increasing subsequence in an array
of n elements. This is a maximum-length sequence of array elements that goes
from left to right, and each element in the sequence is larger than the previous
element.
*/
//O(n log k) where k is the length of LIS i.e if we go more sloppy it will be O(n log n) as k <= n
//This approach uses greedy and Divide and Conquer(binary search)
#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (auto& i : arr) cin >> i;
	int L[n + 1];
	//L[i] stores the minimum ending number among all the lists of length i
	//It is easy to see that L is strictly increasing till curr_lis
	int curr_lis = 1; //curr_lis is the current length of LIS
	L[1] = arr[0];
	for (int i = 1; i < n; i++)
	{
		//binary search in L from index 1 to curr_lis inclusive
		int low = 1, high = curr_lis, mid, ans = -1;
		//ans is the max index for which L[ans] < arr[i] 
		while (low <= high)
		{
			mid = low + (high - low) / 2;
			if (L[mid] < arr[i])
			{
				ans = mid;
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		if (ans == -1)
		{
			//there is no element in L which is smaller than arr[i]
			//Here I am not taking min(L(ans + 1), arr(i)) bcoz it is obvious
			//that arr[i] will only be the min
			L[1] = arr[i];
		}
		else
		{
			L[ans + 1] = arr[i];
			//Here I am not taking min(L(ans + 1), arr(i)) bcoz it is obvious
			//that arr[i] will only be the min
		}
		curr_lis = max(curr_lis, ans + 1);
	}
	cout << curr_lis << '\n'; 	
}
