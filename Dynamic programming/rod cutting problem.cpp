#include <bits/stdc++.h>
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

// Recursive solution
int max_profit(int prices[], int n)  // O(NK)
{
	if (n <= 0)
		return 0;

	int ans = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		int cut = i + 1;

		int current_ans = prices[i] + max_profit(prices, n - cut);
		ans = max(ans, current_ans);
	}

	return ans;
}

// DP Bottom Up
int max_profit_bu(int *prices, int n)
{
	int dp[n + 1] = {};

	for (int len = 1; len <= n; len++)
	{
		int ans = INT_MIN;
		for (int i = 0; i < len; i++)
		{
			int cut = i + 1;
			int current_ans = prices[i] + dp[len - cut];
			ans = max(current_ans, ans);
		}

		dp[len] = ans;
	}

	return dp[n];
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int prices[] = {3, 5, 8, 9, 10, 17, 17, 20};
	int n = sizeof(prices) / sizeof(int);

	cout << max_profit(prices, n) << endl;
	cout << max_profit_bu(prices, n);
}
