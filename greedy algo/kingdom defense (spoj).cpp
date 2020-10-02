// https://www.spoj.com/problems/DEFKIN/

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
	w(t)
	{
		int w, h, n;
		cin >> w >> h >> n;
		if (n == 0)
		{
			cout << w*h << endl;
			continue;
		}
		int a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		sort(a, a + n);
		sort(b, b + n);
		int q = a[0] - 1;
		int s = b[0] - 1;
		for (int i = 0; i < n - 1; i++)
		{
			int d = a[i + 1] - a[i] - 1;
			int k = b[i + 1] - b[i] - 1;
			q = max(q, d);
			s = max(s, k);
		}
		q = max(q, w - a[n - 1]);
		s = max(s, h - b[n - 1]);
		cout << q*s << endl;
		cin.get();
	}
}
