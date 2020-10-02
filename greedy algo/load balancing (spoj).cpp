// https://www.spoj.com/problems/BALIFE/
// We checked for every partition of 1 to i and i+1 to n that what is the maximum load we can transfer from part to another.

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

int main()
{
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
	int t;
	cin >> t;
	while (t != -1)
	{
		int a[t];
		ll sum = 0;
		for (int i = 0; i < t; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		int y = sum / t;
		if (sum % t)
			cout << -1 << endl;
		else
		{
			int m = 0;
			for (int i = t - 1; i > 0; i--)
			{
				sum -= a[i];
				int p = abs(i * y - sum);
				m = max(m, p);
			}
			cout << m << endl;
		}
		cin.get();
		cin >> t;
	}
}
