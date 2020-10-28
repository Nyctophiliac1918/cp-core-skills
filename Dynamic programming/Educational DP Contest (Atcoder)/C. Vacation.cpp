#include <bits/stdc++.h>
/*#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip> //for setprecision()
#include <cstring> //for memset()*/
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define w(x) int x; cin>>x; while(x--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int a[n][3] = {};
	rep(i, n) rep(j, 3) cin >> a[i][j];

	/*To solve this problem, we will maintain a 2D array, dp[n][3].
	dp[i][0] will store the maximum points we can gain by doing activity A on day i.
	dp[i][1] will store the maximum points we can gain by doing activity B on day i.
	dp[i][2] will store the maximum points we can gain by doing activity C on day i. */

	int dp[n][3] = {};
	dp[0][0] = a[0][0], dp[0][1] = a[0][1], dp[0][2] = a[0][2];

	/*// If we do activity A today, we have to have done activities B or C on the previous day.
	dp[i][0] = a[i][0] + max(dp[i - 1][1], dp[i - 1][2]);

	// If we do activity B today, we have to have done activities A or C on the previous day.
	dp[i][1] = a[i][1] + max(dp[i - 1][0], dp[i - 1][2]);

	// If we do activity C today, we have to have done activities A or B on the previous day.
	dp[i][2] = a[i][2] + max(dp[i - 1][1], dp[i - 1][0]); */

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = a[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = a[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = a[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}
