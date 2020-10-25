// n -> n/3, n/2, n-1
// We need to find the minimum no of steps to reach 1.

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

int minSteps(int n, int dp[])  // top down
{
	if (n == 1)
		return 0;

	if (dp[n] != 0)
		return dp[n];

	int x, y, z;
	x = y = z = INT_MAX;

	if (n % 3 == 0)
		x = minSteps(n / 3, dp) + 1;
	if (n % 2 == 0)
		y = minSteps(n / 2, dp) + 1;
	z = minSteps(n - 1, dp) + 1;

	int ans = min(min(x, y), z);
	return dp[n] = ans;
}

int minStepsBU(int n)  // bottom up
{
	if (n == 0)
		return 0;

	int dp[n + 1] = {};
	dp[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		int x, y, z;
		x = y = z = INT_MAX;

		if (i % 3 == 0)
			x = dp[i / 3];
		if (i % 2 == 0)
			y = dp[i / 2];
		z = dp[i - 1];

		dp[i] = min(min(x, y), z) + 1;
	}

	return dp[n];
}

int main()
{
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int n = 15;
	int dp[n + 1] = {};

	cout << minSteps(n, dp);
	cout << endl;
	cout << minStepsBU(n);

}
