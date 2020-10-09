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

int minCoins(int n, int dp[], int coins[], int c) // top down
{
	if (n == 0)
		return 0;

	if (dp[n] != 0)
		return dp[n];

	int ans = INT_MAX;
	rep(i, c)
	{
		if (n - coins[i] >= 0)
		{
			int subprob = minCoins(n - coins[i], dp, coins, c);
			ans = min(ans, subprob + 1);
		}
	}

	return dp[n] = ans;
}

int main()
{
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int n = 7;
	int coins[] = {1, 7, 10};
	int c = sizeof(coins) / sizeof(coins[0]);
	int dp[n + 1] = {};

	cout << minCoins(n, dp, coins, c);
}
