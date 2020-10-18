// Taking input as n and k where n is the number of steps and k is the max no of steps one can jump at a time.

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

int ladders_topdown(int n, int k, int dp[])
{
	if (n == 0)
		return 1;

	if (dp[n] != 0)
		return dp[n];

	int ways = 0;
	for (int i = 1; i <= k; i++)
	{
		if (n - i >= 0)
			ways += ladders_topdown(n - i, k, dp);
	}

	return dp[n] = ways;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k, dp[100] = {};
	cin >> n >> k;

	cout << ladders_topdown(n, k, dp);

	return 0;
}
