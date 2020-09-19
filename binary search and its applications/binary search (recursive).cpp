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

int binary_search(int a[], int l, int r, int m)
{
	if (l > r)
		return -1;
	int mid = l + (r - l) / 2;
	if (a[mid] == m)
		return mid;
	else if (a[mid] > m)
		return binary_search(a, l, mid - 1, m);
	else
		return binary_search(a, mid + 1, r, m);
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
	cout << binary_search(a, 0, n - 1, m);
}
