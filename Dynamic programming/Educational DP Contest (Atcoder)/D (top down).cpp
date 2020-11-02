#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define w(x) int x; cin>>x; while(x--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll knapsack(ll w[], ll v[], ll W, ll n, vector < vector<ll> > &dp)
{
	if (n == 0 || W == 0)
		return 0;

	if (dp[n][W] != -1)
		return dp[n][W];

	if (w[n - 1] <= W)
		return dp[n][W] = max(v[n - 1] + knapsack(w, v, W - w[n - 1], n - 1, dp), knapsack(w, v, W, n - 1, dp));

	return dp[n][W] = knapsack(w, v, W, n - 1, dp);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	FAST
	ll n, W;
	cin >> n >> W;

	ll w[n], v[n];
	rep(i, n) cin >> w[i] >> v[i];

	vector<vector<ll>>dp(n + 1, vector<ll>(W + 1, -1));

	cout << knapsack(w, v, W, n, dp);
}
