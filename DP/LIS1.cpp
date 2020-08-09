/*Our first problem is to find the longest increasing subsequence in an array
of n elements. This is a maximum-length sequence of array elements that goes
from left to right, and each element in the sequence is larger than the previous
element.
*/
//O(n^2)
//This approach uses dp
#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for (auto& i : arr) cin >> i;
	int length[n]; //length[i] denotes the length of the longest increasing subsequence that ends at index k
	int index[n];
	for (int i = 0; i < n; i++)
	{
		length[i] = 1;
		index[i] = -1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				if (length[j] + 1 > length[i])
				{
					index[i] = j;
					length[i] = length[j] + 1;
				}
			}
		}
	}
	int ans = -1;
	int start;
	for (int i = 0; i < n; i++)
	{
		if (length[i] > ans)
		{
			start = i;
			ans = length[i];
		}
	}
	cout << "The LIS length is " << ans << '\n';
	cout << "The LIS is ";
	stack<int> nums;
	while (start >= 0)
	{
		//cout << arr[start] << ' ';
		nums.push(arr[start]);
		start = index[start];
	}
	while (!nums.empty())
	{
		cout << nums.top() << ' ';
		nums.pop();
	}
}
