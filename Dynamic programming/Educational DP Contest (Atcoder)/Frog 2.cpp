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

	int n, k;
	cin >> n >> k;

	vector<int>a(n);
	rep(i, n) cin >> a[i];

	vector<int>dp(n, INT_MAX);
	dp[0] = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (i - j >= 0)
			{
				dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
			}
			else break;
		}
	}

	cout << dp[n - 1];
}
