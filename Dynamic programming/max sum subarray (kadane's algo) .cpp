#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip> //for setprecision()
#include <cstring> //for memset()
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define w(x) int x; cin>>x; while(x--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int maxSum(int a[], int n)
{
	int dp[100] = {0};
	dp[0] = a[0] > 0 ? a[0] : 0;
	int max_so_far = dp[0];

	for (int i = 1; i < n; i++)
	{
		dp[i] = dp[i - 1] + a[i];
		if (dp[i] < 0)
			dp[i] = 0;
		max_so_far = max(dp[i], max_so_far);
	}

	return max_so_far;
}

// Space optimised code
// Kadane's algo
int maxSumSpaceOpt(int a[], int n)
{
	int current_sum = 0;
	int max_so_far = 0;

	for (int i = 0; i < n; i++)
	{
		current_sum += a[i];
		if (current_sum < 0)
			current_sum = 0;
		max_so_far = max(current_sum, max_so_far);
	}

	return max_so_far;
}

// There could be a case when all the numbers in the array are negative. You might have to print the smallest -ve number if the question says the subarray can't be empty.

int main()
{
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int a[] = { -3, 2, 5, -1, 6, 3, -2, 7, -5, 2};
	int n = sizeof(a) / sizeof(int);

	cout << maxSum(a, n) << endl;
	cout << maxSumSpaceOpt(a, n);

	return 0;
}
