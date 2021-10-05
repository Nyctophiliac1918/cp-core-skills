#include <bits/stdc++.h>
using namespace std;
// template<typename... T>
// void see(T&... args) { ((cin >> args), ...);}
// template<typename... T>
// void put(T&&... args) { ((cout << args << " "), ...);}
// template<typename... T>
// void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n';}
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
#define pll pair<long long,long long>
#define endl "\n"
#define pi 3.1415926536
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 1e9 + 7;

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

int dp[1010][1010];

int solve(int h, int a, int i) {
	// cout << h << " " << a << endl;

	if (h <= 0 || a <= 0) return 0;

	if (dp[h][a] != -1) return dp[h][a];

	int m = INT_MIN;

	if (i != 1) m = max(m, 1 + solve(h + 3, a + 2, 1));
	if (i != 2) m = max(m, 1 + solve(h - 5, a - 10, 2));
	if (i != 3) m = max(m, 1 + solve(h - 20, a + 5, 3));

	return dp[h][a] = m;
}

int main()
{
	FAST
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	w(t) {

		int n, m, a;
		cin >> n >> m;
		n--, m--;
		vector<int>h, v;

		int t = n;
		while (t--) cin >> a, v.pb(a);
		t = m;
		while (t--) cin >> a, h.pb(a);

		// rep(i, n) cout << v[i] << " ";

		sort(v.begin(), v.end(), greater<int>());
		sort(h.begin(), h.end(), greater<int>());

		int vc = 1, hc = 1, i = 0, j = 0, ans = 0;

		while (i < n && j < m) {
			if (v[i] >= h[j]) {
				ans += v[i] * hc;
				vc++;
				i++;
			}
			else {
				ans += h[j] * vc;
				hc++;
				j++;
			}
		}

		while (i < n) {
			ans += v[i] * hc;
			i++;
		}

		while (j < m) {
			ans += h[j] * vc;
			j++;
		}

		cout << ans << endl;

	}

	return 0;

}
