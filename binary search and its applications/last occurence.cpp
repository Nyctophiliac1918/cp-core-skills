#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iomanip> //for setprecision()
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define w(x) int x; cin>>x; while(x--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int firstOcc(int a[], int n, int m)
{
	int l = 0, r = n - 1;
	int ans = -1;

	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] == m)
		{
			//do the two things.
			ans = mid;
			l = mid + 1;
		}
		else if (a[mid] > m)
			r = mid - 1;
		else l = mid + 1;
	}

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	rep(i, n) cin >> a[i];
	int m;
	cin >> m;
	cout << firstOcc(a, n, m);
}
