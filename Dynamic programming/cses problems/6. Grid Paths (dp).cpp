#include <bits/stdc++.h>
#define in(x) int x; cin>>x;
#define w(x) int x; cin>>x; while(x--)
#define ll long long int
#define lin(x) ll x; cin>>x;
#define vi vector<int>
#define si set<int>
#define pb push_back
#define rep(i,n) for(int i=0; i<n; i++)
#define pe(i,a,b) for(int i=a; i<=b; i++)
#define rre(i,n) for(int i=n-1; i>-1; i--)
#define mp make_pair
#define pii pair<ll,ll>
#define endl "\n"
#define pi 3.1415926536
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 1e9 + 7;
using namespace std;

int dp[1005][1005] = {};
char a[1005][1005] = {};

int path(int n)
{
	for (int i = 1; i < n; i++)
	{
		if (a[i][0] != '*')
			dp[i][0] = dp[i - 1][0];

		if (a[0][i] != '*')
			dp[0][i] = dp[0][i - 1];
	}

	for (int i = 1 ; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (a[i][j] != '*')
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
		}
	}

	return dp[n - 1][n - 1] % 1000000007;

}

int main()
{
	FAST
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	rep(i, n) rep(j, n) cin >> a[i][j];
	memset(dp, 0, sizeof(dp));

	if (a[0][0] == '*')
	{
		cout << 0;
		return 0;
	}
	else dp[0][0] = 1;

	cout << path(n) << endl;

	// rep(i, n) {
	// 	rep(j, n) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}
