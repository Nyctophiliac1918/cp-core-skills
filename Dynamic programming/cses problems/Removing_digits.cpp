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

int dp[1000005] = {};

int digits(int n) {

	//cout << n << endl;

	if (n == 0) return 0;

	if (dp[n] != -1)
		return dp[n];

	string s = to_string(n);

	int ans = INT_MAX;

	rep(i, s.size())
	{
		if (n - s[i] + 48 >= 0 && s[i] != 48)
		{
			int sub = digits(n - s[i] + 48);

			if (sub != INT_MAX)
				ans = min(ans, sub + 1);
			else ans = min(ans, sub);
		}
	}

	return dp[n] = ans;
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
	memset(dp, -1, sizeof(dp));

	if (digits(n) == INT_MAX)
		cout << -1;
	else cout << digits(n);
}
