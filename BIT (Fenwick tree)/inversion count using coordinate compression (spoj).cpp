// For bigger or negative values, you need to use coordinate compression method. You use set and map to change the values of the elements from 1 to n, and then use the fenwick tree.

#include <bits/stdc++.h>
/*#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip> //for setprecision()
#include <cstring> //for memset()*/
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

		set<int>s;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			s.insert(a[i]);
		}

		map<int, int>m;
		int p = 1;
		for (auto it = s.begin(); it != s.end(); it++)
		{
			if (m.find(*it) == m.end())
			{
				m[*it] = p;
				p++;
			}
		}

		ll ans = 0;
		//Here BIT stores the frequency of digits.
		for (int i = n; i >= 1; i--)
		{
			auto it = m.find(a[i]);
			ans += query(it->second - 1);
			update(it->second, 1, n);
			//cout << it->second << " ";
		}

		cout << ans << endl;

		cin.get();

		memset(BIT, 0, sizeof(BIT));   //putting everything back to 0.
	}
}
