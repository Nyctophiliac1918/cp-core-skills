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
	// cin >> t;
	while (t--)
	{
		long long n, m, a, b, c;
		cin >> n >> m;

		vector<long long>par(n + 1, -1), dist(n + 1, 1e9);
		vector<pair<long long, pair<long long, long long>>>v(m);

		long long i = 0;
		while (m--) {
			cin >> a >> b >> c;
			v[i++] = {a, {b, c}};
			// int x = v[i - 1].first, y = v[i - 1].second.first, z = v[i - 1].second.second;
			// cout << x << " " << y << " " << z << endl;
		}

		dist[v[0].first] = 0;

		for (int i = 0; i < n - 1; i++) {
			for (auto p : v) {
				int x = p.first, y = p.second.first, z = p.second.second;
				// cout << x << " " << y << " " << z << endl;
				if (dist[x] + z < dist[y])
				{
					dist[y] = dist[x] + z;
					par[y] = x;
					// cout << x << " " << y << " " << par[y] << endl;
				}
			}
			// for (int j = 0; j <= n; j++) cout << dist[j] << " ";
			// cout << endl;
		}

		// for (int j = 1; j <= n; j++) cout << par[j] << " ";

		int l = -1;
		vector<long long>ans;

		for (auto p : v) {
			int x = p.first, y = p.second.first, z = p.second.second;
			if (dist[x] + z < dist[y])
			{
				l = y;
				break;
			}
		}

		// cout << l << endl;

		if (l == -1) cout << "NO";
		else {
			for (int i = 1; i <= n; i++)
				l = par[l];
			long long f = l;
			cout << "YES" << endl;
			ans.push_back(f);
			f = par[f];
			while (f != l) {
				ans.push_back(f);
				f = par[f];
			}
			ans.push_back(f);
			reverse(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << " ";
		}
	}
	return 0;

}
