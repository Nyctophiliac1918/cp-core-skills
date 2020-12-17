#include <bits/stdc++.h>
using namespace std;
#define in(x) int x; cin>>x;
#define w(x) int x; cin>>x; while(x--)
#define ll long long int
#define lin(x) ll x; cin>>x;
#define vi vector<int>
#define si set<int>
#define pb push_back
#define re(i,n) for(int i=0; i<n; i++)
#define pe(i,a,b) for(int i=a; i<=b; i++)
#define rre(i,n) for(int i=n-1; i>-1; i--)
#define mp make_pair
#define pii pair<ll,ll>
#define endl "\n"
#define pi 3.1415926536
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, p;
	cin >> n >> p;

	float ans = 0;
	float inc = 1.0;

	for (int times = 0; times <= p; times++)
	{

		while (ans * ans <= n)
			ans = ans + inc;

		ans = ans - inc;
		inc /= 10;
	}

	cout << ans;
}
