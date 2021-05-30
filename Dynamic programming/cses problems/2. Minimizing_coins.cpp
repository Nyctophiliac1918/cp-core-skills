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
#define int1 long long
using namespace std;
 
int N = 1e9 + 7;
 
int dp[1000005] = {};
 
int coins(int *a, int n, int x) {
	//cout << x << " ";
 
	if (x == 0) return 0;
 
	if (dp[x] != -1)
		return dp[x];
 
	int ans = INT_MAX;
	//cout << ans << endl;
 
	for (int i = 0; i < n; i++)
	{
		if (x - a[i] >= 0)
		{
			int sub = coins(a, n, x - a[i]);
 
			if (sub != INT_MAX)
				ans = min(ans, sub + 1);
			else ans = min(ans, sub);
		}
	}
 
	return dp[x] = ans;
}
 
int main()
{
	FAST
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	int n, x;
	cin >> n >> x;
	int a[n];
	rep(i, n) cin >> a[i];
	memset(dp, -1, sizeof(dp));
 
	if (coins(a, n, x) == INT_MAX)
		cout << -1;
	else cout << coins(a, n, x);
}
