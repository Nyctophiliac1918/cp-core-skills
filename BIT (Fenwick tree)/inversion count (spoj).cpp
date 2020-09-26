//https://www.spoj.com/problems/INVCNT/
// This is also called point update, range query.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip> //for setprecision()
#include <cstring> //for memset()
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define w(x) int x; cin>>x; while(x--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int a[200005] = {0};
int BIT[10000005] = {0};

void update(int i, int val, int n)
{
	while (i <= n)
	{
		BIT[i] += val;
		i += (i & (-i));
	}
}

int query(int i)
{
	int ans = 0;
	while (i > 0)
	{
		ans += BIT[i];
		i -= (i & (-i));
	}
	return ans;
}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	FAST
	w(t)
	{
		cin.get();
		int n;
		cin >> n;

		int p = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			p = max(p, a[i]);
		}

		//Here BIT stores the frequency of digits.
		ll ans = 0;
		for (int i = n; i >= 1; i--)
		{
			ans += query(a[i] - 1);
			update(a[i], 1, p);
		}
		cout << ans << endl;

		cin.get();

		memset(BIT, 0, sizeof(BIT));   //putting everything back to 0.
	}
}
