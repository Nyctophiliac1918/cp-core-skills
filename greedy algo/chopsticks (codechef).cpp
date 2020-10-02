// https://www.codechef.com/problems/TACHSTCK
// We will sort the array and then check if two consecutive sticks are <=d and if not then any other pair could also not satisfy this requirement. So we will check further.

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
	int n, d;
	cin >> n >> d;
	int l[n];
	rep(i, n) cin >> l[i];
	sort(l, l + n);
	int k = 0;
	for (int i = 0; i < n - 1;)
	{
		if (l[i + 1] - l[i] <= d)
		{
			k++;
			i += 2;
		}
		else i++;
	}
	cout << k;
}
