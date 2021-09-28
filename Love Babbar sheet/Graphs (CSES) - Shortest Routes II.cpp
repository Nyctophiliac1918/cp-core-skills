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
#define pii pair<int,int>
#define endl "\n"
#define pi 3.1415926536
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 1e9 + 7;
using namespace std;

int dp[4][4005] = {};

// int path(int n)
// {
// 	for (int i = 1; i < n; i++)
// 	{
// 		if (a[i][0] != '*')
// 			dp[i][0] = dp[i - 1][0];

// 		if (a[0][i] != '*')
// 			dp[0][i] = dp[0][i - 1];
// 	}

// 	for (int i = 1 ; i < n; i++)
// 	{
// 		for (int j = 1; j < n; j++)
// 		{
// 			if (a[i][j] != '*')
// 				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
// 		}
// 	}

// 	return dp[n - 1][n - 1] % 1000000007;

// }

void solve(int i, int p, int n, int& ans, vector<int>& v, int k) {
	if (i >= n) return;

	if (p * v[i] < k)
	{
		ans++;
		solve(i + 1, p * v[i], n, ans, v, k);
	}
	solve(i + 1, p, n, ans, v, k);

}

int main()
{
	FAST
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	while (t--) {

		int n, m, q;
		cin >> n >> m >> q;
		vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, LONG_MAX));

		rep(i, n + 1) rep(j, n + 1) if (i == j) dist[i][j] = 0;

		long long a, b, c;
		while (m--) {
			cin >> a >> b >> c;
			dist[a][b] = dist[b][a] = min(dist[a][b], c);
		}

		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (dist[i][k] == LONG_MAX || dist[k][j] == LONG_MAX) continue;
					else if (dist[i][k] + dist[k][j] < dist[i][j])
						dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}

		// rep(i, n + 1) {
		// 	rep(j, n + 1) cout << dist[i][j] << " ";
		// 	cout << endl;
		// }

		while (q--) {
			cin >> a >> b;
			if (dist[a][b] == LONG_MAX) cout << -1 << endl;
			else cout << dist[a][b] << endl;
		}

	}

}
