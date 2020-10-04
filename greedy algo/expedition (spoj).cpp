// https://www.spoj.com/problems/EXPEDI/
// We used greaady approach with max heap over here.

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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, tx, d, f, D, F;
	w(t)
	{
		int flag = 0, ans = 0;
		vector<pair<int, int>>v;
		priority_queue<int>pq;

		cin >> n;

		rep(i, n)
		{
			cin >> d >> f;
			v.push_back(make_pair(d, f));
		}

		cin >> D >> F;

		rep(i, n) v[i].first = D - v[i].first;

		sort(v.begin(), v.end());

		int prev = 0, x = 0;

		while (x < n)
		{
			if (F >= (v[x].first - prev)) {
				F -= (v[x].first - prev);
				pq.push(v[x].second);
				prev = v[x].first;
			}
			else {
				if (pq.empty())
				{
					flag = 1;
					break;
				}
				F += pq.top(); //Refueling wih the highest amount of fuel available.
				pq.pop(); //Coz we have used it.
				ans++;
				continue;
			}
			x++;
		}
    
		// Getting out of loop means we have reached fuelling stations, now we have to check if we can reach town using the available fuel.
		if (flag)
		{
			cout << -1 << endl;
			continue;
		}

		D -= v[n - 1].first;

		if (F >= D)
		{
			cout << ans << endl;
			continue;
		}

		while (F < D)
		{
			if (pq.empty())
			{
				flag = 1;
				break;
			}
			F += pq.top();
			pq.pop();
			ans++;
		}

		if (flag)
			cout << -1 << endl;
		else cout << ans << endl;
	}
}
