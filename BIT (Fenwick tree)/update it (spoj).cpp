// We will update the values in Fenwick tree from l to r. First, by updating it from l to last element and then subtracting val from r+1 to last element. Then, give the answer to query.
https://www.spoj.com/problems/UPDATEIT/
// range update, point query

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

int BIT[100005] = {0};

void update(int i, int val, int n)
{
	while (i <= n)
	{
		BIT[i] += val;
		i += (i & (-i));
	}
}

ll query(int i)
{
	ll ans = 0;
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
		int n;
		cin >> n;

		w(u)
		{
			int l, r, val;
			cin >> l >> r >> val;

			update(l + 1, val, n);
			update(r + 2, -val, n);
		}

		w(q)
		{
			int a;
			cin >> a;

			cout << query(a + 1) << endl;
		}
	}
}
