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
 
int dice(int n)
{
	if (n == 0)
		return 1;
 
	if (dp[n] != -1)
		return dp[n];
 
	int cnt = 0;
 
	pe(i, 1, 6) {
		if (n - i >= 0)
			cnt = cnt % N + dice(n - i) % N;
	}
 
	return dp[n] = cnt % N ;
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
 
	cout << dice(n);
}
