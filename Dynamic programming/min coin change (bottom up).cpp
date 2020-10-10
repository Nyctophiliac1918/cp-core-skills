// min coin change
// coins[] = {1,7,10}

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

int minCoins(int n, int coins[], int c)
{
	if (n == 0)
		return 0;

	int dp[n + 2] = {};

	for (int i = 1; i <= n; i++)
	{
		dp[i] = INT_MAX;
		for (int t = 0; t < c; t++)
		{
			if (i - coins[t] >= 0)
			{
				int subprob = dp[i - coins[t]];
				dp[i] = min(dp[i], subprob + 1);
			}
			else break;
		}
	}

	return dp[n];
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

	cout << minCoins(n, coins, c);
}
